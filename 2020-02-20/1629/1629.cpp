#include <cstdio>
#include <math.h>

long long getPower(long long A, long long B, long long mod);

int main(){
	long long A, B, C;
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", getPower(A, B, C)%C);
}

long long getPower(long long A, long long B, long long mod){
	if(B == 0)
		 return 1;
	long long temp = (getPower(A, B/2, mod));

	if(B % 2 == 0)
		return (temp%mod * temp%mod) % mod;
	else 
		return (temp%mod * temp%mod * A)%mod;
}