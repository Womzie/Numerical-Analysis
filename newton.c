/*

The interval bisection method works iff 
the function is continuous and you can 
establish an initial left & right guess, 
such that:
   f(left) and f(right) have different signs
(i.e.: one is positive and the other negative)

COMPILE THIS CODE BY RUNNING:

gcc interval_bisection04_lab.c -lm

The -lm links with the math library

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1 (double x)
{
  double y ;
  y = x*x - 2 ;
  return y ;
}


double f2 (double x)
//  three roots,
//  -3 - sqrt(3) = -4.732050,
//  -3 + sqrt(3) = -1.267949,
//   6
{
  double y ;
  y = x*x*x - 30*x - 36 ;
  return y ;
}




int main()
{
  double x, f, n;
  scanf("%lf",&x);
  f = n = x;
  for(int i = 1; i <= 15; i++){
    f = cbrt(30*f + 36);
    n = n - (n*n*n - 30*n - 36)/(3*n*n - 30);
    printf("%20.16lf %20.16lf \n", f, n);
  }
}
