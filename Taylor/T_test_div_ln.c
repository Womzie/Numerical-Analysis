#include "TaylorS.c"

double h = 1e-5 ;

double f (double x)
{
  double y ;
  y = log(x*x*x - 2*x + 3) - log(x*x + 1) ;
  return y ;
}

double f1 (double x)
{
  double y ;
  y = (f(x+h) - f(x-h))/(2*h) ;
  return y ;
}


double f2 (double x)
{
  double y ;
  y = (f1(x+h) - f1(x-h))/(2*h) ;
  return y ;
}


double f3 (double x)
{
  double y ;
  y = (f2(x+h) - f2(x-h))/(2*h) ;
  return y ;
}

double f4 (double x)
{
  double y ;
  y = (f3(x+h) - f3(x-h))/(2*h) ;
  return y ;
}


double f5 (double x)
{
  double y ;
  y = (f4(x+h) - f4(x-h))/(2*h) ;
  return y ;
}




int main()
//  Find the Taylor sequence for
//  exp(x*x*x - 2*x + 3) / exp(x^2 + 1)
//  with x = 0.75 through degree 5 
{
  double x = 0.75 ;
  double X[100],X2[100],X3[100],A[100],B[100],C[100],D[100],LA[100],LC[100] ;
  double S[100],LD[100] ;
  
  Tdegree = 5 ;

  make_variable_T (X, x)   ;
  
  Mul_T           (X2, X,X)  ; // X2 = X^2
  Mul_T           (X3, X2,X) ; // X3 = X^3 

  
  copy_T          (A, X3)    ; // A = X^3

  
  copy_T          (B,  X)    ; // B = X
  Mul_cons_T      (B,  2)    ; // B = 2X
  Sub_T           (A,  A,B)  ; // A = X^3 - 2X
  Add_cons_T      (A,  3)    ; // A = X^3 - 2X + 3

  copy_T          (C,  X2)   ; // C = X^2
  Add_cons_T      (C,  1)    ; // c = X^2 + 1


  Div_T           (D, A,C)   ; // D = exp(X^3 - 2X + 3)/exp(X^2 + 1)

  ln_T           (LD,D)       ;

  ln_T           (LA,  A)    ; // EA = exp(X^3 - 2X + 3)
  ln_T           (LC,  C)    ; // EC = exp(X^2 + 1)
  Sub_T          (S, LA,LC)     ;
 
  
  
  print_T("The answer is ", " %lf", LD, "\n") ;
  print_T("The answer is ", " %lf", S, "\n") ;
  
  printf("\nFinite diff   : ") ;
  printf("%lf  %lf  %lf  %lf  %lf  %lf\n",
	 f(x), f1(x), f2(x)/2, f3(x)/6, f4(x)/24, f5(x)/120 ) ;
  
}

