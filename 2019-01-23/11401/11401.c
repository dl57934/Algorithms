#include <stdio.h>

#define mod 1000000007

long long facto(long long operator, long long limit);
long long calculate(long long limit, long long operator);

int main(){
	int N, K;
	long long result;
	long long molecule,denominator;

	scanf("%d %d", &N, &K);

	molecule = facto(1, N);
 	denominator = facto(1, K);
	denominator = facto(denominator, N-K);

	result = (molecule*calculate(mod-2 ,denominator))%mod;

	printf("%lld", result);
}

long long facto(long long operator, long long limit){
	for(int i = 1; i<=limit; i++){
		operator*=i;
		operator%=mod;
	}
	return operator%mod;
}

long long calculate(long long limit, long long operator){
	long long result = operator;
	long long power = 1;
	while(limit>0){
		if(limit%2!=0){
			result*=operator;
			result%=mod;
		}
		operator*=operator;
		operator%=mod;
		power+=1;
		limit/=2;
	}
	return result%mod;
}