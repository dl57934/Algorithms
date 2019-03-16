#include <stdio.h>

int main(){
	int N, nSize;
	scanf("%d", &N);
	int save = N;

	for(int i = 1; i <= 1000000; i*=10){
		if( N/i < 10){
			nSize = i;
			break;
		}
	}
	nSize*=10;

	for(int operator = 1; operator < N; operator++){
		int saveOperator = operator;
		int calculOperator = operator;
		for(int operand=1; operand<=nSize; operand*=10 ){
				if(operator<10){
					saveOperator+=operator;
					break;
				}
				else{
					if(operand>=10){
						saveOperator+=(calculOperator%operand)/(operand/10);
						calculOperator-=(calculOperator%operand);
					}
				}
		}
		if(saveOperator==N){
			printf("%d\n", operator);
			return 0;
		}
	}
	printf("0\n");
}