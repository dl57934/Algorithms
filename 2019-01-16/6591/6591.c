#include <stdio.h>

#define P 1000000007

long long factorial(long long operator, long long limit);
long long calculOrder(long long operator, long long limit);

int main(){
	long long n, k;
	long long result;
	scanf("%lld %lld", &n, &k);
	long long A = factorial(1, n);
	long long B = factorial(1, k);
	B = factorial(B, n-k);
	B = calculOrder(B, P-2);

	B%=P;
	result = A*B;
	result%=P;
	printf("%lld", result);
}

long long factorial(long long operator, long long limit){
	for(long long i = 1; i <= limit;i++){
		operator*=i;
		operator%=P;
	}
	return operator;
}

long long calculOrder(long long operator, long long limit){
	long long result = 1;

	while(limit>0){
		if(limit%2!=0){
			result*=operator;
			result%=P;
		}
		operator*=operator;
		operator%=P;
		limit/=2;
	}
	return result;
}