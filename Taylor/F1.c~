#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double h = 1e-5 ;

double f(double x){
  double num = 17  +  (14 - 8*cos(x) + cos(2*x)) * cos(2*x)   - 24*cos(x);
  double denom =   (x*exp(x) - x) * (1 + 2*x*x - cos(2*x) - 4*x*sin(x));

  double result = num / denom;

  return result;
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

int main(){

  double x = 1;

  printf("%lf  %lf  %lf  %lf  %lf  %lf\n",
	 f(x), f1(x), f2(x)/2, f3(x)/6, f4(x)/24, f5(x)/120 ) ;
}

/* 

Compute the limit of 


 17  +  [14 - 8*cos(x) + cos(2*x)] * cos(2*x)   - 24*cos(x)
------------------------------------------------------------
  [x*exp(x) - x] * [1 + 2*x*x - cos(2*x) - 4*x*sin(x)]


as x approaches 0.

The answer is pleasant.

*/





