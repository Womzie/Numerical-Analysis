

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>


// Make work with complex numbers
// Goal is to find all complex roots, (try a bunch of starting spots)

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


int main()
{
  int degree, k;
  double V;

  complex a[100], x, f ,d;
  scanf("%d", &degree);

  for(k = degree; k >= 0; k--){
    scanf("%lf", &V);
    a[k] = V + 0*I;
    
  }

  // printf("input x(complex) ");
  // x = sccmx();

  x =  1 + 0*I;

  complex e = x;

  for(int i = 1; i <= 10; i++){
    f = 0;
    d = 0;
    for( k = 0; k <= degree; k++){
      f = f + a[k] * (e * x);
      d = d + k * a[k] * e;
      e *= x;
    }
    //prcmx("%lf", x);printf(" ");
    //prcmx("%lf", f); printf(" ");
    //prcmx("%lf", d); printf("\n");
    x = x - f/d;
  }
  prcmx("%lf", x);
 
}
