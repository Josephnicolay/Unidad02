#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
	double value;
	value = cos(x) -x;
	return value;
}
double dfdx(double x){
	double value;
	value=-sin(x)-1.0;
	return value;
}


// Toda rutina en C debe tener una rutina principal
int main(void){

	/*vamos a encontrar la raíz de la ecuación 
	 f(x) = cos(x) -x, usando el método de Newton - Raphson*/
	double tol;//tolerancia
	int Nmax;//Número máximo de iteraciones 
	double p;//p_(n)
	double p_prev;//p_(n-1)
	double error;
	int iteration;

	p_prev=5.0;
	error=1.0;
	Nmax=1000;

	while(error>tol){
	p=p_prev - f(p_prev)/dfdx(p_prev);
	error = fabs(p-p_prev);
	p_prev=p;
	iteration=iteration +1;
	if (iteration>Nmax){
		printf("El metodo no converge despues de %d iteraciones",Nmax);
		
		break;
	}
	
	printf("p_n=%.16f\t error=%.16f\t abs(f(p))=%.16f\t \n",p,error,fabs(f(p)));

	}

	return 0;
}
