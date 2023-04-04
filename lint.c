#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef
long int
lint ;


int main()
{
  int a,b,c ;
  a = 2123456789 ;
  b = 2123456789 ;
  c = a + b ;
  printf("%d + %d = %d\n",a,b,c) ;

  lint x,y,z ;
  x = 2123456789 ;
  y = 2123456789 ;
  z = x + y ;
  printf("%ld + %ld = %ld\n",x,y,z) ;

  lint e,f,g;
  e = 10;
  f = 10;
  g = powl(e,f);
  
  printf("%ld ^ %ld = %ld\n",e,f,g) ;
  
}
