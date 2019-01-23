#include <stdio.h>

long long calculate(long long operator, long long limit, long long mod);

int main(){
	long long A,B,C;
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", calculate(A, B, C));
}

long long calculate(long long operator, long long limit, long long mod){
	long long result = 1;

	while(limit > 0){
		if(limit%2 != 0){
			result *= operator;
			result%=mod;
		}
		operator*=operator;
		operator%=mod;
		limit/=2;
	}

	return result;
}