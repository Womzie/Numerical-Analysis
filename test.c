
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

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


int main(){
  double x = 0;
  int numsteps = 100;
  double goal = 1;goal /= 7;
  for(int i = 1; i < numsteps; i++){
    x = ((10-(1/goal))*x + 1)/10;
    printf("%lf\n",x);
  }
}
