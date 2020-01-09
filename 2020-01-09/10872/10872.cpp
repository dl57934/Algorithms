#include <stdio.h>

int factorial(int n);

int main(){
	int N;
	scanf("%d", &N);
	printf("%d",  factorial(N));
}

int factorial(int n){
	if( n == 1 || n == 0)
		return 1;
	else 
		return factorial(n-1) * n;
}