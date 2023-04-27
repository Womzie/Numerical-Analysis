#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "TaylorStudent.c"


double f(double x){
  double num = 17  +  (14 - 8*cos(x) + cos(2*x)) * cos(2*x)   - 24*cos(x);
  double denom =   (x*exp(x) - x) * (1 + 2*x*x - cos(2*x) - 4*x*sin(x));;

  double result = num / denom;

  return result;
}


int main(){
  Tdegree = 10;

  double X[100], X2[100], A[100], B[100], C[100], a[100], b[100], c[100];
  double E[100], F[100], p[100], y[100], z[100];
  double N[100], D[100], Q[100];
  double x = 0;

  make_variable_T(X, x);
  make_variable_T(X2, 2*x);
  make_constant_T(A, 17);

  make_constant_T(a, 14);
  
  cos_T(b, X);
  Mul_cons_T(b, 8);

  cos_T(c, X2);

  Sub_T(B, a, b);
  Add_T(B, B, c);

  Mul_T(B, B, c);

  cos_T(C, X);
  Mul_cons_T(C, 24);

  Add_T(N, A, B);
  Sub_T(N, N, C);

  exp_T(E, X);
  Mul_T(E, X, E);
  Sub_T(E, E, X);

  make_constant_T(y, 1);
  
  Mul_T(p, X, X);
  Mul_cons_T(p, 2);

  sin_T(z, X);
  Mul_T(z, z, X);
  Mul_cons_T(z, 4);

  Add_T(F, y, p);
  Sub_T(F, F, c);
  Sub_T(F, F, z);

  Mul_T(D, E, F);

  Div_T(Q, N, D);
  
  
  print_T("", "%lf", N, "\n");
   print_T("", "%lf", D, "\n");
  

}

/* 

Compute the limit of 


 17  +  [14 - 8*cos(x) + cos(2*x)] * cos(2*x) - 24*cos(x)
------------------------------------------------------------
  [x*exp(x) - x] * [1 + 2*x*x - cos(2*x) - 4*x*sin(x)]


as x approaches 0.

The answer is pleasant.

*/





