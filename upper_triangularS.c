#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int len = 20;

int backSub(double m[len][len], int n){
  double result[n];

  for(int i = n; i > 0; i--){
    double sum = 0;
    for(int j = 1; j <= n; j++){
      sum += result[j] * m[i][j];
    }
    result[i] = (m[i][n+1] - sum)/m[i][i];
  }

  for(int i = 1; i <= n; i++){
    printf("\t%4.2f", result[i]);
  }
  printf("\n");
}
int main()
{
  char fname[100] ;
  FILE *f ;
  double m[len][len] ;
  int n ;
  int r,c ;

  printf("enter the name of the file to be read : ") ;
  scanf("%s", fname) ;
  f = fopen(fname, "r") ;
  if (f == NULL) {
    printf("can't read file\n") ;
    exit(0) ;
  }
  
  fscanf(f,"%d",&n) ;
  for (r = 1 ; r <= n ; r++) {
    for (c = 1 ; c <= n+1 ; c++) {
      fscanf(f,"%lf", &m[r][c]) ;
    }
  }

  
  printf("\n") ;  
  for (r = 1 ; r <= n ; r++) {
    for (c = 1 ; c <= n+1 ; c++) {
      printf("%10.5lf", m[r][c]) ;
    }
    printf("\n") ;
  }  
  printf("\n") ;

  backSub(m, n);
  
}
