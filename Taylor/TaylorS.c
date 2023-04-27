#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int Tdegree ;



int print_T (char before[], char control[], double t[], char after[])
// control is the control string for the doubles
// that will be printed
{
   int k ;

   printf("%s",before) ;
   printf("[") ;
   for (k = 0 ; k <= Tdegree ; k++) {
       printf(control,t[k]) ;
       if (k != Tdegree) { printf(",") ;}
   }
   printf("]") ;
   printf("%s",after) ;
   return 1 ;
}



int copy_T (double dest[], double source[])
{
  int k ;
  for (k = 0 ; k <= Tdegree ; k++) {
    dest[k] = source[k] ;
  }
  return 1 ;
}



int make_constant_T(double t[], double v)
{
  int k ;
  for (k = 0 ; k <= Tdegree ; k++ ) t[k] = 0 ;
  t[0] = v ;
  return 1 ;
}


int make_variable_T(double t[], double v)
// essentially makes a linear with value, v
{
  int k ;
  for (k = 0 ; k <= Tdegree ; k++ ) t[k] = 0 ;

  t[0] = v ;
  t[1] = 1 ;
  return 1 ;
}


//////////////////////////////////////////////////////////
// should be safe for any and all of these parameter
// pointers to point to same things



int Add_cons_T (double r[], double constant)
// r =  r + constant
{
  r[0] += constant ;
  return 1 ;
}



int Mul_cons_T (double r[], double constant)
// r =  r * constant
{
  int n ;

  for ( n = 0 ; n <= Tdegree ; n++ ) {
    r[n] *= constant ;
  }
  return 1 ;
}







int Add_T (double r[], double u[], double v[])
// r = u + v
{
  int k ;

  for (k = 0 ; k <= Tdegree ; k++ ) {
        r[k] = u[k] + v[k] ;
  }

  return 1 ;
}




int Sub_T (double r[], double u[], double v[])
// r = u - v
{
  int k ;

  for (k = 0 ; k <= Tdegree ; k++ ) {
      r[k] = u[k] - v[k] ;
  }

  return 1 ;
}



int Mul_T (double r[], double u[], double v[])
// r = u * v
{
  int n,k ;
  double sum ;
  double p[1000] ;

  for ( n = 0 ; n <= Tdegree ; n++ ) {

     sum = 0.0 ;
     for ( k = 0 ; k <= n ; k++ ) {
        sum = sum + u[k] * v[n-k] ;
     }

     p[n] = sum ;
  }
  
  copy_T (r,p) ;
  return 1 ;

}

int Div_T(double r[], double u[], double v[]){
  int n, k;
  double sum;
  double p[1000];
  if(v[0] == 0){
    return 0;
  }
  for ( n = 0 ; n <= Tdegree ; n++){
    sum = 0.0;

    sum += u[n];
    for( k = 0; k < n; k++){
      
      sum -= p[k] * v[n-k];
    }

    sum /= v[0];
    
    p[n] = sum;
  }
  copy_T (r,p);
  return 1;
}

int exp_T (double r[],  double u[]){
  int n, k;
  double sum;
  double p[1000];

  p[0] = exp(u[0]);
  //printf("%lf \n",p[0]);
  for( n = 1; n <= Tdegree ; n++){
    sum = 0.0;

    for( k = 1 ; k <= n ; k++){
      sum += k * p[n-k] * u[k];
    }
  sum /= n;

  p[n] = sum;
  }
  copy_T (r, p);
  return 1;

}

int ln_T(double r[], double u[]){
  int n, k;
  double sum;
  double p[1000];

  p[0] = log(u[0]);
  
  for( n = 1; n <= Tdegree ; n++){
    sum = u[n];
    //printf("%lf \n" , p[n-1]);
    for( k = 1 ; k < n ; k++){
      sum -= k * p[k] * u[n-k];
    }

    
    sum /= (n * u[0]);

    
    p[n] = sum;
  }

  //printf("%lf \n", p[1]);
  copy_T (r, p);
  return 1;

  
}

int cossin_T(double c[], double s[], double u[]){
   int n, k;
   double pc[1000], ps[1000];
   
  pc[0] = cos(u[0]);
  ps[0] = sin(u[0]);

  for (int n = 1; n <= Tdegree; n++) {
    double sumC = 0;
    double sumS = 0;

    for (int k = 0; k < n; k++) {
      sumC -= (n - k) * ps[k] * u[n - k];
      sumS += (n - k) * pc[k] * u[n - k];
    }

    sumC /= n;
    sumS /= n;

    pc[n] = sumC;
    ps[n] = sumS;
  }

  copy_T(c, pc);
  copy_T(s, ps);

  return 1;

}

int cos_T(double c[], double u[]){

  double s[1000];

  cossin_T(c, s, u);

  return 1;
}

int sin_T(double s[], double u[]){
  double c[1000];

  cossin_T(c,s,u);

  return 1;
}

int tan_T(double r[], double u[]){
  double c[1000], s[1000], p[1000];

  cossin_T(c,s,u);

  Div_T(p, s,c);

  copy_T(r, p);

  return 1;
  
}
