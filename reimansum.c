

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>


// Make work with complex numbers
// Goal is to find all complex roots, (try a bunch of starting spots)

// Print Complex Number //

double f(double x){
  double y;
  y = (6 * pow(x,2)) + (4 * x) ;

  return y;
}



// Sets the second array equal to the first array
void setEquals(complex a[100], complex b[100]){
  for(int i = 0; i < 100; i ++){
    b[i] = a[i]; 
  }
}

double rSumRect(){
  double l,r, s;

  printf("outer left, right, subdivisions \n");
  scanf("%lf %lf %lf", &l, &r, &s);

  double dif = (r - l);
  dif /= s;
  double rSum = 0;
  
  for(double i = l; i < r - (dif/2) ; i += dif){
    rSum += f(i) * dif;
    //printf("%lf \n", i);
  }

  printf("%lf \n", rSum);
}

double trapSum(){
  double l,r, s;

  printf("outer left, right, subdivisions \n");
  scanf("%lf %lf %lf", &l, &r, &s);

  double dif = (r - l) / s;
  double rSum = (f(l) + f(r)) / 2;
  double prev = f(l);
  double x = l;

  
  for(int i = 1; i <= s-1; i ++){
    x += dif;
    rSum += f(x);
    
  }

  rSum *= dif;

  printf("%lf \n", rSum);

}

int main()
{
  //rSumRect();
  trapSum();
  
  // synthdiv(a, degree, 0, a);
	
}
