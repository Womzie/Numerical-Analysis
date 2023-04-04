#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// FIXED POINT ITERATION
// x^3 - 30x - 36 solve for x
int main(){
  int i;
  double X, y;
  X = 1;
  for(i = 1; i <= 30; i++){
    X = 36/(X*X - 30);
    printf("%20.16lf \n", X);
    }

  y = pow(X,3) - (30 * X) - 36;
  printf("%lf \n",y);
  
}
