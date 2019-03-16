#include <stdio.h>
#include <math.h>

#define ull unsigned long long

int visit[1001000] = {0, };

int isPrime(int N);

int main(){
	ull min, max;
	ull count = 0;

	scanf("%lld %lld", &min, &max);
	count = max-min+1;
	
	for(ull i=2;i<=1001000; i++){
		if(isPrime(i) && i<max){
			int primeNumber=i;
			do{
				primeNumber+=i;
				count-=1;
			}while(primeNumber<=max);
		}else
			break;
	}
	printf("%llu", count);
}

int isPrime(int N){
	for(int i = 2; i <= sqrt(N); i++){
		if(N%i==0)
			return 0;
	}
	return 1;
}