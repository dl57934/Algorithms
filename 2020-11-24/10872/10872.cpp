#include <cstdio>

int factorial(int N);

int main(){
	int N;
	scanf("%d", &N);
	printf("%d", factorial(N));
}

int factorial(int N){
	if(N == 0)
		return 1;
	return N * factorial(N - 1);
}