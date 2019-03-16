#include <stdio.h>
#include <math.h>

int isPrimeNumber(int number);

int main(){
	int N;
	int number, count = 0;
	scanf("%d", &N);
	for(int i = 0; i <N; i++){
		scanf("%d", &number);
		if(number!=1&&isPrimeNumber(number))
			count++;
	}
	printf("%d", count);
}

int isPrimeNumber(int number){
	for(int i = 2; i <= sqrt(number); i++)
		if(number%i==0)
			return 0;
	return 1;
}