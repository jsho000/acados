/* This function was automatically generated by CasADi */
#ifdef __cplusplus
extern "C" {
#endif

#ifdef CODEGEN_PREFIX
  #define NAMESPACE_CONCAT(NS, ID) _NAMESPACE_CONCAT(NS, ID)
  #define _NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else /* CODEGEN_PREFIX */
  #define CASADI_PREFIX(ID) jac_chain_nm3_ ## ID
#endif /* CODEGEN_PREFIX */

#include <math.h>

#ifndef real_t
#define real_t double
#define to_double(x) (double) x
#define to_int(x) (int) x
#endif /* real_t */

/* Pre-c99 compatibility */
#if __STDC_VERSION__ < 199901L
real_t CASADI_PREFIX(fmin)(real_t x, real_t y) { return x<y ? x : y;}
#define fmin(x,y) CASADI_PREFIX(fmin)(x,y)
real_t CASADI_PREFIX(fmax)(real_t x, real_t y) { return x>y ? x : y;}
#define fmax(x,y) CASADI_PREFIX(fmax)(x,y)
#endif

#define PRINTF printf
real_t CASADI_PREFIX(sq)(real_t x) { return x*x;}
#define sq(x) CASADI_PREFIX(sq)(x)

real_t CASADI_PREFIX(sign)(real_t x) { return x<0 ? -1 : x>0 ? 1 : x;}
#define sign(x) CASADI_PREFIX(sign)(x)

static const int CASADI_PREFIX(s0)[] = {12, 1, 0, 12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
#define s0 CASADI_PREFIX(s0)
static const int CASADI_PREFIX(s1)[] = {3, 1, 0, 3, 0, 1, 2};
#define s1 CASADI_PREFIX(s1)
static const int CASADI_PREFIX(s2)[] = {12, 12, 0, 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132, 144, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
#define s2 CASADI_PREFIX(s2)
/* jacFun */
int jac_chain_nm3(void* mem, const real_t** arg, real_t** res, int* iw, real_t* w) {
    mem = 0; mem += 0; w = 0; w += 0; iw = 0; iw += 0;
  real_t a0=arg[0] ? arg[0][3] : 0;
  if (res[0]!=0) res[0][0]=a0;
  a0=arg[0] ? arg[0][4] : 0;
  if (res[0]!=0) res[0][1]=a0;
  a0=arg[0] ? arg[0][5] : 0;
  if (res[0]!=0) res[0][2]=a0;
  a0=arg[0] ? arg[0][6] : 0;
  real_t a1=arg[0] ? arg[0][0] : 0;
  a0=(a0-a1);
  real_t a2=sq(a0);
  real_t a3=arg[0] ? arg[0][7] : 0;
  real_t a4=arg[0] ? arg[0][1] : 0;
  a3=(a3-a4);
  real_t a5=sq(a3);
  a2=(a2+a5);
  a5=arg[0] ? arg[0][8] : 0;
  real_t a6=arg[0] ? arg[0][2] : 0;
  a5=(a5-a6);
  real_t a7=sq(a5);
  a2=(a2+a7);
  a2=sqrt(a2);
  a7=3.3000000000000002e-02;
  real_t a8=(a7/a2);
  real_t a9=1.;
  real_t a10=(a9-a8);
  real_t a11=(a10*a0);
  real_t a12=sq(a1);
  real_t a13=sq(a4);
  a12=(a12+a13);
  a13=sq(a6);
  a12=(a12+a13);
  a12=sqrt(a12);
  a7=(a7/a12);
  a13=(a9-a7);
  real_t a14=(a13*a1);
  a11=(a11-a14);
  a14=3.3333333333333336e+01;
  a11=(a14*a11);
  if (res[0]!=0) res[0][3]=a11;
  a11=(a10*a3);
  real_t a15=(a13*a4);
  a11=(a11-a15);
  a11=(a14*a11);
  if (res[0]!=0) res[0][4]=a11;
  a11=(a10*a5);
  a15=(a13*a6);
  a11=(a11-a15);
  a11=(a14*a11);
  a15=9.8100000000000005e+00;
  a11=(a11-a15);
  if (res[0]!=0) res[0][5]=a11;
  a11=arg[0] ? arg[0][9] : 0;
  if (res[0]!=0) res[0][6]=a11;
  a11=arg[0] ? arg[0][10] : 0;
  if (res[0]!=0) res[0][7]=a11;
  a11=arg[0] ? arg[0][11] : 0;
  if (res[0]!=0) res[0][8]=a11;
  a11=arg[1] ? arg[1][0] : 0;
  if (res[0]!=0) res[0][9]=a11;
  a11=arg[1] ? arg[1][1] : 0;
  if (res[0]!=0) res[0][10]=a11;
  a11=arg[1] ? arg[1][2] : 0;
  if (res[0]!=0) res[0][11]=a11;
  a11=0.;
  if (res[1]!=0) res[1][0]=a11;
  if (res[1]!=0) res[1][1]=a11;
  if (res[1]!=0) res[1][2]=a11;
  a8=(a8/a2);
  a15=(a0/a2);
  a15=(a8*a15);
  real_t a16=(a0*a15);
  a16=(a16+a10);
  a7=(a7/a12);
  real_t a17=(a1/a12);
  a17=(a7*a17);
  real_t a18=(a1*a17);
  a18=(a18+a13);
  a16=(a16+a18);
  a16=(a14*a16);
  a16=(-a16);
  if (res[1]!=0) res[1][3]=a16;
  a16=(a3*a15);
  a18=(a4*a17);
  a16=(a16+a18);
  a16=(a14*a16);
  a16=(-a16);
  if (res[1]!=0) res[1][4]=a16;
  a15=(a5*a15);
  a17=(a6*a17);
  a15=(a15+a17);
  a15=(a14*a15);
  a15=(-a15);
  if (res[1]!=0) res[1][5]=a15;
  if (res[1]!=0) res[1][6]=a11;
  if (res[1]!=0) res[1][7]=a11;
  if (res[1]!=0) res[1][8]=a11;
  if (res[1]!=0) res[1][9]=a11;
  if (res[1]!=0) res[1][10]=a11;
  if (res[1]!=0) res[1][11]=a11;
  if (res[1]!=0) res[1][12]=a11;
  if (res[1]!=0) res[1][13]=a11;
  if (res[1]!=0) res[1][14]=a11;
  a15=(a3/a2);
  a15=(a8*a15);
  a17=(a0*a15);
  a16=(a4/a12);
  a16=(a7*a16);
  a18=(a1*a16);
  a17=(a17+a18);
  a17=(a14*a17);
  a17=(-a17);
  if (res[1]!=0) res[1][15]=a17;
  a17=(a3*a15);
  a17=(a17+a10);
  a18=(a4*a16);
  a18=(a18+a13);
  a17=(a17+a18);
  a17=(a14*a17);
  a17=(-a17);
  if (res[1]!=0) res[1][16]=a17;
  a15=(a5*a15);
  a16=(a6*a16);
  a15=(a15+a16);
  a15=(a14*a15);
  a15=(-a15);
  if (res[1]!=0) res[1][17]=a15;
  if (res[1]!=0) res[1][18]=a11;
  if (res[1]!=0) res[1][19]=a11;
  if (res[1]!=0) res[1][20]=a11;
  if (res[1]!=0) res[1][21]=a11;
  if (res[1]!=0) res[1][22]=a11;
  if (res[1]!=0) res[1][23]=a11;
  if (res[1]!=0) res[1][24]=a11;
  if (res[1]!=0) res[1][25]=a11;
  if (res[1]!=0) res[1][26]=a11;
  a15=(a5/a2);
  a15=(a8*a15);
  a16=(a0*a15);
  a12=(a6/a12);
  a7=(a7*a12);
  a1=(a1*a7);
  a16=(a16+a1);
  a16=(a14*a16);
  a16=(-a16);
  if (res[1]!=0) res[1][27]=a16;
  a16=(a3*a15);
  a4=(a4*a7);
  a16=(a16+a4);
  a16=(a14*a16);
  a16=(-a16);
  if (res[1]!=0) res[1][28]=a16;
  a15=(a5*a15);
  a15=(a15+a10);
  a6=(a6*a7);
  a6=(a6+a13);
  a15=(a15+a6);
  a15=(a14*a15);
  a15=(-a15);
  if (res[1]!=0) res[1][29]=a15;
  if (res[1]!=0) res[1][30]=a11;
  if (res[1]!=0) res[1][31]=a11;
  if (res[1]!=0) res[1][32]=a11;
  if (res[1]!=0) res[1][33]=a11;
  if (res[1]!=0) res[1][34]=a11;
  if (res[1]!=0) res[1][35]=a11;
  if (res[1]!=0) res[1][36]=a9;
  if (res[1]!=0) res[1][37]=a11;
  if (res[1]!=0) res[1][38]=a11;
  if (res[1]!=0) res[1][39]=a11;
  if (res[1]!=0) res[1][40]=a11;
  if (res[1]!=0) res[1][41]=a11;
  if (res[1]!=0) res[1][42]=a11;
  if (res[1]!=0) res[1][43]=a11;
  if (res[1]!=0) res[1][44]=a11;
  if (res[1]!=0) res[1][45]=a11;
  if (res[1]!=0) res[1][46]=a11;
  if (res[1]!=0) res[1][47]=a11;
  if (res[1]!=0) res[1][48]=a11;
  if (res[1]!=0) res[1][49]=a9;
  if (res[1]!=0) res[1][50]=a11;
  if (res[1]!=0) res[1][51]=a11;
  if (res[1]!=0) res[1][52]=a11;
  if (res[1]!=0) res[1][53]=a11;
  if (res[1]!=0) res[1][54]=a11;
  if (res[1]!=0) res[1][55]=a11;
  if (res[1]!=0) res[1][56]=a11;
  if (res[1]!=0) res[1][57]=a11;
  if (res[1]!=0) res[1][58]=a11;
  if (res[1]!=0) res[1][59]=a11;
  if (res[1]!=0) res[1][60]=a11;
  if (res[1]!=0) res[1][61]=a11;
  if (res[1]!=0) res[1][62]=a9;
  if (res[1]!=0) res[1][63]=a11;
  if (res[1]!=0) res[1][64]=a11;
  if (res[1]!=0) res[1][65]=a11;
  if (res[1]!=0) res[1][66]=a11;
  if (res[1]!=0) res[1][67]=a11;
  if (res[1]!=0) res[1][68]=a11;
  if (res[1]!=0) res[1][69]=a11;
  if (res[1]!=0) res[1][70]=a11;
  if (res[1]!=0) res[1][71]=a11;
  if (res[1]!=0) res[1][72]=a11;
  if (res[1]!=0) res[1][73]=a11;
  if (res[1]!=0) res[1][74]=a11;
  a15=(a0/a2);
  a15=(a8*a15);
  a6=(a0*a15);
  a6=(a6+a10);
  a6=(a14*a6);
  if (res[1]!=0) res[1][75]=a6;
  a6=(a3*a15);
  a6=(a14*a6);
  if (res[1]!=0) res[1][76]=a6;
  a15=(a5*a15);
  a15=(a14*a15);
  if (res[1]!=0) res[1][77]=a15;
  if (res[1]!=0) res[1][78]=a11;
  if (res[1]!=0) res[1][79]=a11;
  if (res[1]!=0) res[1][80]=a11;
  if (res[1]!=0) res[1][81]=a11;
  if (res[1]!=0) res[1][82]=a11;
  if (res[1]!=0) res[1][83]=a11;
  if (res[1]!=0) res[1][84]=a11;
  if (res[1]!=0) res[1][85]=a11;
  if (res[1]!=0) res[1][86]=a11;
  a15=(a3/a2);
  a15=(a8*a15);
  a6=(a0*a15);
  a6=(a14*a6);
  if (res[1]!=0) res[1][87]=a6;
  a6=(a3*a15);
  a6=(a6+a10);
  a6=(a14*a6);
  if (res[1]!=0) res[1][88]=a6;
  a15=(a5*a15);
  a15=(a14*a15);
  if (res[1]!=0) res[1][89]=a15;
  if (res[1]!=0) res[1][90]=a11;
  if (res[1]!=0) res[1][91]=a11;
  if (res[1]!=0) res[1][92]=a11;
  if (res[1]!=0) res[1][93]=a11;
  if (res[1]!=0) res[1][94]=a11;
  if (res[1]!=0) res[1][95]=a11;
  if (res[1]!=0) res[1][96]=a11;
  if (res[1]!=0) res[1][97]=a11;
  if (res[1]!=0) res[1][98]=a11;
  a2=(a5/a2);
  a8=(a8*a2);
  a0=(a0*a8);
  a0=(a14*a0);
  if (res[1]!=0) res[1][99]=a0;
  a3=(a3*a8);
  a3=(a14*a3);
  if (res[1]!=0) res[1][100]=a3;
  a5=(a5*a8);
  a5=(a5+a10);
  a14=(a14*a5);
  if (res[1]!=0) res[1][101]=a14;
  if (res[1]!=0) res[1][102]=a11;
  if (res[1]!=0) res[1][103]=a11;
  if (res[1]!=0) res[1][104]=a11;
  if (res[1]!=0) res[1][105]=a11;
  if (res[1]!=0) res[1][106]=a11;
  if (res[1]!=0) res[1][107]=a11;
  if (res[1]!=0) res[1][108]=a11;
  if (res[1]!=0) res[1][109]=a11;
  if (res[1]!=0) res[1][110]=a11;
  if (res[1]!=0) res[1][111]=a11;
  if (res[1]!=0) res[1][112]=a11;
  if (res[1]!=0) res[1][113]=a11;
  if (res[1]!=0) res[1][114]=a9;
  if (res[1]!=0) res[1][115]=a11;
  if (res[1]!=0) res[1][116]=a11;
  if (res[1]!=0) res[1][117]=a11;
  if (res[1]!=0) res[1][118]=a11;
  if (res[1]!=0) res[1][119]=a11;
  if (res[1]!=0) res[1][120]=a11;
  if (res[1]!=0) res[1][121]=a11;
  if (res[1]!=0) res[1][122]=a11;
  if (res[1]!=0) res[1][123]=a11;
  if (res[1]!=0) res[1][124]=a11;
  if (res[1]!=0) res[1][125]=a11;
  if (res[1]!=0) res[1][126]=a11;
  if (res[1]!=0) res[1][127]=a9;
  if (res[1]!=0) res[1][128]=a11;
  if (res[1]!=0) res[1][129]=a11;
  if (res[1]!=0) res[1][130]=a11;
  if (res[1]!=0) res[1][131]=a11;
  if (res[1]!=0) res[1][132]=a11;
  if (res[1]!=0) res[1][133]=a11;
  if (res[1]!=0) res[1][134]=a11;
  if (res[1]!=0) res[1][135]=a11;
  if (res[1]!=0) res[1][136]=a11;
  if (res[1]!=0) res[1][137]=a11;
  if (res[1]!=0) res[1][138]=a11;
  if (res[1]!=0) res[1][139]=a11;
  if (res[1]!=0) res[1][140]=a9;
  if (res[1]!=0) res[1][141]=a11;
  if (res[1]!=0) res[1][142]=a11;
  if (res[1]!=0) res[1][143]=a11;
  return 0;
}

int jac_chain_nm3_init(int* n_in, int* n_out, int* n_int, int* n_real) {
  if (n_in) *n_in = 2;
  if (n_out) *n_out = 2;
  if (n_int) *n_int = 0;
  if (n_real) *n_real = 0;
  return 0;
}

int jac_chain_nm3_alloc(void** mem, const int* idata, const double* rdata) {
  if (mem) *mem = 0;
  (void)idata;
  (void)rdata;
  return 0;
}

int jac_chain_nm3_free(void* mem) {
  (void)mem;
  return 0;
}

int jac_chain_nm3_sparsity(int i, int *nrow, int *ncol, const int **colind, const int **row) {
  const int* s;
  switch (i) {
    case 0:
    case 2:
      s = s0; break;
    case 1:
      s = s1; break;
    case 3:
      s = s2; break;
    default:
      return 1;
  }

  if (nrow) *nrow = s[0];
  if (ncol) *ncol = s[1];
  if (colind) *colind = s + 2;
  if (row) *row = s + 3 + s[1];
  return 0;
}

int jac_chain_nm3_work(int *sz_arg, int* sz_res, int *sz_iw, int *sz_w) {
  if (sz_arg) *sz_arg = 2;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 19;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
