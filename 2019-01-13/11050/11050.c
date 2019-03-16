#include <stdio.h>

int factorial(int N);

int main(){
	int N,K;
	scanf("%d %d", &N, &K);
	int result = factorial(N)/(factorial(K)*factorial(N-K));
	printf("%d", result);
}

int factorial(int N){
	if(N > 0){
		return factorial(N-1) * N;
	}else{
		return 1;
	}
}