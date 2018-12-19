%% test of native matlab interface
clear all



%% arguments
compile_mex = 'true';
codgen_model = 'true';
param_scheme = 'multiple_shooting_unif_grid';
N = 20;

nlp_solver = 'sqp';
%nlp_solver = 'sqp_rti';
qp_solver = 'partial_condensing_hpipm';
%qp_solver = 'full_condensing_hpipm';
qp_solver_N_pcond = 5;
%sim_method = 'erk';
sim_method = 'irk';
sim_method_num_stages = 4;
sim_method_num_steps = 3;



%% create model entries
model = linear_mass_spring_model;
%model_funs = crane_model;

% dims
T = 10.0; % horizon length time
nx = model.nx;
nu = model.nu;
nyl = nu+nx; % number of outputs in lagrange term
nym = nx; % number of outputs in mayer term
if 1
	nbx = nx/2;
	nbu = nu;
	ng = 0;
	nh = 0;
elseif 0
	nbx = 0;
	nbu = 0;
	ng = nu+nx/2;
	nh = 0;
else
	nbx = 0;
	nbu = 0;
	ng = 0;
	nh = nu+nx;
end
% cost
Vul = zeros(nyl, nu); for ii=1:nu Vul(ii,ii)=1.0; end % input-to-output matrix in lagrange term
Vxl = zeros(nyl, nx); for ii=1:nx Vxl(nu+ii,ii)=1.0; end % state-to-output matrix in lagrange term
Vxm = zeros(nym, nx); for ii=1:nx Vxm(ii,ii)=1.0; end % state-to-output matrix in mayer term
Wl = eye(nyl); for ii=1:nu Wl(ii,ii)=2.0; end % weight matrix in lagrange term
Wm = eye(nym); % weight matrix in mayer term
yrl = zeros(nyl, 1); % output reference in lagrange term
yrm = zeros(nym, 1); % output reference in mayer term
% constraints
x0 = zeros(nx, 1); x0(1)=2.5; x0(2)=2.5;
if (ng>0)
	D = zeros(ng, nu); for ii=1:nu D(ii,ii)=1.0; end
	C = zeros(ng, nx); for ii=1:nx/2 C(nu+ii,ii)=1.0; end
	lg = zeros(ng, 1); for ii=1:nu lg(ii)=-0.5; end; for ii=1:nx/2 lg(nu+ii)=-4.0; end
	ug = zeros(ng, 1); for ii=1:nu ug(ii)= 0.5; end; for ii=1:nx/2 ug(nu+ii)= 4.0; end
elseif (nh>0)
	lh = zeros(nh, 1); for ii=1:nu lh(ii)=-0.5; end; for ii=1:nx lh(nu+ii)=-4.0; end
	uh = zeros(nh, 1); for ii=1:nu uh(ii)= 0.5; end; for ii=1:nx uh(nu+ii)= 4.0; end
else
	Jbx = zeros(nbx, nx); for ii=1:nbx Jbx(ii,ii)=1.0; end
	lbx = -4*ones(nx, 1);
	ubx =  4*ones(nx, 1);
	Jbu = zeros(nbu, nu); for ii=1:nbu Jbu(ii,ii)=1.0; end
	lbu = -0.5*ones(nu, 1);
	ubu =  0.5*ones(nu, 1);
end




%% acados ocp model
ocp_model = acados_ocp_model();
% dims
ocp_model.set('T', T);
ocp_model.set('nx', nx);
ocp_model.set('nu', nu);
ocp_model.set('nyl', nyl);
ocp_model.set('nym', nym);
if (ng>0)
	ocp_model.set('ng', ng);
elseif (nh>0)
	ocp_model.set('nh', nh);
else
	ocp_model.set('nbx', nbx);
	ocp_model.set('nbu', nbu);
end
% symbolics
ocp_model.set('sym_x', model.sym_x);
if isfield(model, 'sym_u')
	ocp_model.set('sym_u', model.sym_u);
end
if isfield(model, 'sym_xdot')
	ocp_model.set('sym_xdot', model.sym_xdot);
end
% cost
ocp_model.set('Vul', Vul);
ocp_model.set('Vxl', Vxl);
ocp_model.set('Vxm', Vxm);
ocp_model.set('Wl', Wl);
ocp_model.set('Wm', Wm);
ocp_model.set('yrl', yrl);
ocp_model.set('yrm', yrm);
% dynamics
if (strcmp(sim_method, 'erk'))
	ocp_model.set('dyn_type', 'expl');
	ocp_model.set('expr_f', model.expr_expl);
else % irk
	ocp_model.set('dyn_type', 'impl');
	ocp_model.set('expr_f', model.expr_impl);
end
% constraints
ocp_model.set('x0', x0);
if (ng>0)
	ocp_model.set('C', C);
	ocp_model.set('D', D);
	ocp_model.set('lg', lg);
	ocp_model.set('ug', ug);
elseif (nh>0)
	ocp_model.set('expr_h', model.expr_h);
	ocp_model.set('lh', lh);
	ocp_model.set('uh', uh);
else
	ocp_model.set('Jbx', Jbx);
	ocp_model.set('lbx', lbx);
	ocp_model.set('ubx', ubx);
	ocp_model.set('Jbu', Jbu);
	ocp_model.set('lbu', lbu);
	ocp_model.set('ubu', ubu);
end

ocp_model.model_struct



%% acados ocp opts
ocp_opts = acados_ocp_opts();
ocp_opts.set('compile_mex', compile_mex);
ocp_opts.set('codgen_model', codgen_model);
ocp_opts.set('param_scheme', param_scheme);
ocp_opts.set('param_scheme_N', N);
ocp_opts.set('nlp_solver', nlp_solver);
ocp_opts.set('qp_solver', qp_solver);
if (strcmp(qp_solver, 'partial_condensing_hpipm'))
	ocp_opts.set('qp_solver_N_pcond', qp_solver_N_pcond);
end
ocp_opts.set('sim_method', sim_method);
ocp_opts.set('sim_method_num_stages', sim_method_num_stages);
ocp_opts.set('sim_method_num_steps', sim_method_num_steps);

ocp_opts.opts_struct



%% acados ocp
% create ocp
ocp = acados_ocp(ocp_model, ocp_opts);
ocp
ocp.C_ocp
ocp.C_ocp_ext_fun



% set trajectory initialization
x_traj_init = zeros(nx, N+1);
u_traj_init = zeros(nu, N);
ocp.set('x_init', x_traj_init);
ocp.set('u_init', u_traj_init);


% solve
tic;
ocp.solve();
time_solve = toc


x0(1) = 1.5;
ocp.set('x0', x0);


% if not set, the trajectory is initialized with the previous solution


tic;
ocp.solve();
time_solve = toc



% get solution
u = ocp.get('u');
x = ocp.get('x');

u
x




fprintf('\nsuccess!\n\n');


return;
