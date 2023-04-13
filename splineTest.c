#include "FPToolkit.c"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int print_tridiag(double L[], double D[], double R[], double Q[], int n){
  for(int i = 0; i < n; i++){
    for(int j = 1; j < i; j++){
      printf("\t\t");
    }
    if(i > 0){
      printf("%8.2f\t", L[i]);
    }

    printf("%8.2f\t", D[i]);

    if(i < n-1){
      printf("%8.2f\t", R[i]);
    }

    for(int k = n-1; k > i+1; k--){
      printf("\t\t");
    }
    
    printf("%8.5f", Q[i]);

    printf("\n");
  }
}


int tri_diagonal_solver (double L[],
                         double D[],
                         double R[],
                         double Q[],
			                   int n,
                         double x[])
{

	R[0] /= D[0];
	Q[0] /= D[0]; 
	D[0] = 1;


	for(int i = 1; i < n; i++){
		Q[i] = (Q[i] - L[i] * Q[i-1]) / (D[i] - L[i] * R[i-1]);
		
		R[i] /= (D[i] - L[i] * R[i-1]);

		L[i] = 0;
		D[i] = 1;

	}

	print_tridiag(L, D, R, Q, n);

	x[n-1] = Q[n-1];
	for(int j = n-2; j >= 0; j--){
		x[j] = Q[j] - (x[j+1] * R[j]);
	}

	return 1;


}

int build_tridiag(double L[], double D[], double R[], double Z[], int n, double p[], double q[]){
  D[0] = 1;
  R[0] = -(p[1] - p[0]); 
  Z[0] = 0;

  for(int i = 1; i < n-1; i++){
    int pivot = ceill((i+1) / 2);
    printf("%d: %d \n", i, pivot);

    if(i % 2 == 0){
      L[i] = pow((p[pivot] - p[pivot - 1]), 2);
      D[i] = -(p[pivot+1] - p[pivot-1]);
      R[i] = (p[pivot] - p[pivot-1]) * (p[pivot+1] - p[pivot]);

      Z[i] = -Z[i-1];
    }
    else{
      L[i] = p[pivot] - p[pivot-1];
      D[i] = pow((p[pivot] - p[pivot - 1]), 2);
      R[i] = p[pivot + 1] - p[pivot];

      Z[i] =  (q[pivot+1] - q[pivot])/(p[pivot+1] - p[pivot]) - (q[pivot] - q[pivot-1])/(p[pivot] - p[pivot-1]);

    }
  }

  int pivot = ceill((n) / 2);
  L[n-1] = 1;
  D[n-1] = 2 * (p[pivot] - p[pivot - 1]);

  Z[n-1] = 0;
  
  print_tridiag(L, D, R, Z, n);
  return 0;
}


int clickandsave(double *x, double *y)
{
  double xp,yp,p[2] ;
  int numpoints ;

  G_rgb(1, 0, 0) ; // red
  G_fill_rectangle(0,0 ,30,30) ;

  G_rgb(0.5,0.5,0.5) ;
  numpoints = 0 ;
  while (0 == 0) {

     G_wait_click(p) ;
     xp = p[0] ; yp = p[1] ;

     if ((xp >= 0) && (xp <= 30) && 
         (yp >= 0) && (yp <= 30))  { break ; }

     G_fill_rectangle(xp-2, yp-2, 4,4) ;     

     x[numpoints] = xp ; y[numpoints] = yp ; numpoints++ ;

  }

  return numpoints ;
}





int main()
{
  double p[100],q[100] ;
  int n,i ;
  double xb,yb,numer,denom,m ;

  G_init_graphics(800,800) ;
  G_rgb(0,0,0) ; G_clear() ;

  //n = clickandsave(p,q) ;

  
  //int numpoints = n;

  int numpoints = 4;

  p[0] = 215;
  p[1] = 316;
  p[2] = 365;
  p[3] = 481;
  
  q[0] = 480;
  q[1] = 438;
  q[2] = 271;
  q[3] = 170;

  double L[1000],D[1000],R[1000],Z[1000] ;
  double x[1000] ;
  int size = (numpoints -1) * 2;

  for(int i = 0; i < 4; i++){
    G_rgb(0,1,0);
    G_fill_circle(p[i], q[i], 3);
  }

  printf("%d \n", size);

  build_tridiag(L, D, R, Z, size, p, q);

  int s;
  s = tri_diagonal_solver (L,D,R,Z,size,x) ;

  if (s != 1) {
   printf("Could not find a unique solution.\n") ;
   exit(0) ;
  }
  printf("\nSolution to the tridiagonal system is :\n") ;
  for (i = 0 ; i < size ; i++) {
   printf("%lf\n",x[i]) ;
  }
  printf("\n") ;	

  G_rgb(1, 0, 0);

  int xA = 0; 
  int xB = 1;
  for(int j = 1; j < numpoints; j++){
    for(int i = p[j-1]; i < p[j]; i ++){
      double y = q[j-1] + (q[j] - q[j-1])/(p[j] - p[j-1]) * (i - p[j-1]) + (x[xA] * (i - p[j-1]) * (i - p[j])) + (x[xB] * pow((i - p[j-1]), 2) * (i - p[j]));
      G_fill_circle(i, y, 1);
    }
    xA += 2;
    xB += 2;
  }
  
  

  G_wait_key() ;
}
