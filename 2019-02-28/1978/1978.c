#include <stdio.h>
#include <math.h>

int isPrime(int number);

int main(){
	int N, number, prime = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &number);
		if(isPrime(number))
			prime+=1;
	}
	printf("%d", prime);
}

int isPrime(int number){
	
	if(number == 1)
		return 0;

	for(int i = 2; i <=sqrt(number); i++)
		if(number%i == 0)
			return 0;
	return 1;
}