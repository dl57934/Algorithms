#include <stdio.h>

int GCD(int A, int B);
int getMeasure(int num);

int measure[33334]={0,};
int measureCount = 0;
int main(N){
	scanf("%d", &N);
	int caseNum;
	long long int inputNum[102];

	for (int i = 0; i < N;i++)
		scanf("%lld", &inputNum[i]);

	for(int i = 1; i < N; i++)
		inputNum[i] = GCD(inputNum[i], inputNum[i-1]);

	for(int i = 0; i < N; i++)
		printf("%d ", inputNum[i]);
	return 0;
}

long long int getMeasure(long long int num){
	for(int i = 2; i*i <= num; i++){
		if(num%i==0){
			measure[i] = i;
			measureCount+=1;
		}
	}
}

long long int GCD(long long int A, long long int B){
	if(B==0)return A;
	return GCD(B, A%B);
}