

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

complex synthDiv(complex a[], int degree, complex x,  complex deriv[]){

	complex c = 0 + 0*I;
	deriv[degree] = 0;
	for(int i = degree; i > 0; i --){
		deriv[i-1] = x * c + a[i];
		c = deriv[i-1];
		prcmx("%lf", c); printf("l\t");
	}
	printf("\n");
	
	return x * c + a[0];

}

complex synthDivDeriv(complex a[], int degree, complex x){

	complex c = 0 + 0*I;
	for(int i = degree; i > 0; i --){
		c = x * c + a[i];
		
	}

	return x * c + a[0];

}

complex newton(complex a[], int degree, complex x){
	complex f,d;
	for(int i = 1; i <= 1; i++){
		
	  complex b[100];
        prcmx("%lf", x); printf("\n");
            f = synthDiv(a, degree, x, b);
            d = synthDivDeriv(b, degree, x);
		
	    prcmx("%lf", f); printf("\t");
	    prcmx("%lf", d); printf("\t");
            x = x - f/d;
            prcmx("%lf", x); printf("\n");
        }

	return x;
 }

// Sets the second array equal to the first array
void setEquals(complex a[100], complex b[100]){
	for(int i = 0; i < 100; i ++){
		b[i] = a[i]; 
	}
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



	

	  //		x =  0 + 1*I;
	  
		int fDegree = degree;
		complex last[100];
		setEquals(a, last);
		printf("\n\n");
		while(fDegree > 0){
		  x = 1 + 2*I ;
			complex next[100];
			// for(int i = 0; i <= fDegree; i ++){
			//   prcmx("%lf", last[i]); printf("\t");
			// }
			// printf("\n\n");
			x = newton(last, fDegree, x);
			prcmx("%lf", x); printf("\n\n");
		
			synthDiv(last, fDegree, x, next); 
			fDegree--;

			setEquals(next, last);
			
			fDegree = 0;

		}
	


	

 
	// synthdiv(a, degree, 0, a);
	
}
