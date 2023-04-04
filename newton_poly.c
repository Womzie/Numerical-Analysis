#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>


// Make work with complex numbers
// Goal is to find all complex roots, (try a bunch of starting spots)
double coefs[100];
int degree;
double deriv[100];

// Print Complex Number //
void prcmx (char *control, complex c)
{
  double a,b ;
  a = creal(c) ;
  b = cimag(c) ;

  printf(control,a) ;
  if (b >= 0) {
    printf("+") ;
  } else {
    printf("-") ;
  }
  printf(control,fabs(b)) ;  
  printf("I") ;
}

// Scans for Complex Number //
complex sccmx ()
{
  double rp,ip ;
  complex c ;
  scanf("%lf %lf",&rp, &ip) ;
  c = rp + ip*I ;
  return c ;
}


double f (double x)
{
  double sum = 0;
  for(int i = 0; i <= degree; i++){
    sum += coefs[i] * pow(x, i);
  }

  return sum;
}


double fprime (double x)
{
  double sum = 0;
  for(int i = 0; i < degree; i++){
    sum += deriv[i] * pow(x, i);
  }

  return sum;
}


void derivBuilder(){
    for(int i = 0; i < degree; i ++){
    deriv[i] = coefs[i+1] * (i+1);
  }
}

double newton(double n){
  n = n - (f(n) / fprime(n));
  //n = n - (n*n*n - 30*n - 36)/(3*n*n - 30);
  return n;
}

int main()
{

  double n = 5;
  
  scanf("%d",&degree);

  for(int i = 0; i <=degree; i++){
    double temp;
    scanf("%lf", &temp);
    coefs[degree - i] = temp;
  }

  derivBuilder();
  
  for(int i = 0; i < 10; i++){
    n = newton(n);

    printf("%lf \n", n);
  }
}

