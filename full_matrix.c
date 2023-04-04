#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int len = 20;

#define DELTA 1e-13

int triangularize(double m[len][len], int n){
  

  
  for(int i = 1; i < n; i++){
    for(int j = i+1; j <= n; j++){
	
      double max = 0;
      int loc = i;
      
      for(int k = i; k <= n; k++){
	if(m[k][i] > max){
	  max = m[k][i];
	  loc = k;
	}
      }


      double temp;
      for(int k = 1; k <= n+1; k ++){
        temp = m[i][k];
	m[i][k] = m[loc][k];
	m[loc][k] = temp;
      }

      double factor = m[j][i] / m[i][i];
      for(int c = 1; c <= n+1; c++){
	m[j][c] -= factor * m[i][c];
      }
    
    }
  
  }

  int flag = 0;
  for(int i = 1; i <= n; i++){
    if(fabs(m[n][i]) >= DELTA){
      flag++;
    }
  }

  if(flag == 0){
    
    if(fabs(m[n][n+1]) >= DELTA){
      printf("\nInconsistent");
      return 0;
    }
    else{
      printf("\nUnderdetermined");
      return -1;

    }
  }

  return 1;
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
  

  int q = triangularize(m,n);

  printf("\n") ;  
    for (r = 1 ; r <= n ; r++) {
      for (c = 1 ; c <= n+1 ; c++) {
	printf("%10.4f", m[r][c]) ;
      }
      printf("\n") ;
    }  
    printf("\n") ;
  
  double result[n];

  for(int i = n; i > 0; i--){
    double sum = 0;
    for(int j = 1; j <= n; j++){
      sum += result[j] * m[i][j];
    }
    result[i] = (m[i][n+1] - sum)/m[i][i];
  }

 
  
  
  if(q == 1){
     for(int i = 1; i <= n; i++){
       printf("%10.2f", result[i]);
     }
     printf("\n");
  
  }
  else if(q == -1){
    printf("infinite solutions \n");
  }
  else if(q == 0){
    printf("no solutions \n");
  }
  
}
