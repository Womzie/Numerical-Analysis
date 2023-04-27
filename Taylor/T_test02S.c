#include "TaylorS.c"



int main(){
  double x = 0.75 ;
  double X[100],X2[100],X3[100],A[100],B[100],C[100],D[100], E[100], L[100];

  double cos[100], sin[100], tan[100];

  Tdegree = 5;
  make_variable_T(X,x);


  exp_T(E, X);
  Add_T(A, X, E);
  ln_T(L, A);

  
  print_T("The answer is ", " %lf", L, "\n") ;
  
  
  
//   Find the Taylor sequence for
//
//        ln(x+exp(x)) - 3*exp(sin(x))*cos(x)
//       -------------------------------------
//               4 + cos(x + sin(x))
//
//   with x = 1.25 through degree 7.


  // make this happen

  
}

