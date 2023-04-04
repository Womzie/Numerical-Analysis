#include <stdio.h>
#include <stdlib.h>

int main(){
  double x1, x2, x3, x4;
  x1 = x2 = x3 = x4 = 0;

  for(int i = 1; i <= 15; i ++){
    x1 = (498 - 5*x2 - 8*x3 + 2*x4)/100;
    x2 = (834 - 4*x1 - 2*x3 - 6*x4)/200;
    x3 = (6 - 2*x1 - 2*x2 - 4*x4)/10;
    x4 = (255 - 5*x1 - 15*x2 + 10*x3)/50;

    printf("%lf %lf %lf %lf\n", x1, x2, x3, x4);
  }
  return 1;
}
