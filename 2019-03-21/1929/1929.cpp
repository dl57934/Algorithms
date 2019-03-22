#include <cstdio>
#include <math.h>

int isPrimeNumber(int value);

int main(){
	int M, N;
	scanf("%d %d", &M, &N);

	for(int checkVal = M; checkVal <= N; checkVal++){
		if(isPrimeNumber(checkVal))
			printf("%d\n", checkVal);
	}
}

int isPrimeNumber(int value){
	if(value == 1)
		return 0;
	
	for(int i = 2; i <= sqrt(value); i++)
		if(value % i == 0)
			return 0;
	

	return 1;
}