

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>


// Make work with complex numbers
// Goal is to find all complex roots, (try a bunch of starting spots)

// Print Complex Number //

double f(double x){
  double y;
  y = (6 * pow(x,2)) - (8 * x) + 1 + (4 * pow(x,3)) + (pow(x,4)) ;

  return y;
}





double rSumRect(double l, double r, int s){

  double dif = (r - l);
  dif /= s;
  double rSum = 0;
  
  for(double i = l; i < r - (dif/2) ; i += dif){
    rSum += f(i) * dif;
    //printf("%lf \n", i);
  }

  printf("Reimman Sum: %lf \n", rSum);
}

double trapSum(double l, double r, int s){

  double dif = (r - l) / s;
  double rSum = (f(l) + f(r)) / 2;
  double prev = f(l);
  double x = l;

  
  for(int i = 1; i <= s-1; i ++){
    x += dif;
    rSum += f(x);
    
  }

  rSum *= dif;

  printf("Trapezoids: %lf \n", rSum);

}

double simpsons(double l, double r, int s){

  double sum;
  double a, b, m;
  
  double dif = (r - l) / s;
  
  a = l;
  m = a + dif;
  b = m + dif;
  sum = 0;
  
  if(s % 2 == 0){
    for(int i = 0; i < s/2; i++){

      sum += (b-a)/6 * (f(a) + 4 * f(m) + f(b));
      //printf("%lf %lf %lf \n", a, m, b);
      
      a += 2 * dif;
      m += 2 * dif;
      b += 2 * dif;
      
    }
    printf("Simpsons Rule: %lf \n", sum);
  }
  else{
    printf("subdivisions must be even \n");
  }
  
}

double simpsons13(double l, double r, int s){
  double sum = 0;
  double dif = (r - l) / s;
  sum = f(l);
  double x = l + dif;
  if(s % 2 == 0){
    for(int i = 1; i < s; i++){
      //printf("%lf %d \n", x, i);
      if(i % 2 == 0){
	sum += 2 * f(x);
      }
      else{
	sum += 4 * f(x);
      }
      x += dif;
    }
    sum += f(x);
    sum *= dif/3;
    printf("Simpsons 1/3 Rule: %lf \n", sum);
  }
  else{
    printf("subdivisions must be even \n");
  }
  
}

int main()
{
  double l,r;
  int s;
  
  printf("outer left, right, subdivisions \n");
  scanf("%lf %lf %d", &l, &r, &s);
  
  rSumRect(l, r, s);
  trapSum(l, r, s);

  simpsons(l, r, s);
  simpsons13(l, r, s);
  
  // synthdiv(a, degree, 0, a);
	
}
