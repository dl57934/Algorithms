#include <stdio.h>
#include <math.h>

void isPrimeNumber(int normalNum);
int count = 0;

int main(N){
	int inputNum;
	scanf("%d", &N);
	
	for(int i=0; i < N; i++){
		scanf("%d", &inputNum);
		if(inputNum != 1)
			isPrimeNumber(inputNum);
	}

	printf("%d", count);
}

void isPrimeNumber(int normalNum){
	for(int i = 2; i <= sqrt(normalNum); i++){
	 	if(normalNum%i==0){	
	 		return ;
	 	}
	}
	count ++;
}