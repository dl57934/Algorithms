#include <stdio.h>

#define mod 1000000007

long long facto(int limit);
long long calculate(long long denominator);

int main(){
	long long N, K, nMinK;
	long long denominator;
	scanf("%lld %lld", &N, &K);
	nMinK = N-K;
	N = facto(N);
	K = facto(K);
	nMinK = facto(nMinK);
	denominator = (K*nMinK)%mod;
	denominator =calculate(denominator)%mod;
	long long result = (N * denominator)%mod;
	printf("%lld", result);
}

long long facto(int limit){
	long long result = 1;
	for(int i = 2; i<=limit; i++){
		result*=i;
		result%=mod;
	}
	return result%mod;
}

long long calculate(long long denominator){
	long long result=1;
	long long limit = mod-2;
	while(limit > 0){
		if(limit % 2!= 0){
			result*=denominator;
			result%=mod;
		}
		denominator*=denominator;
		denominator%=mod;
		limit/=2;
	}
	return result%mod;
}





