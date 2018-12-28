#include <stdio.h>

long long int GCD(long long int A, long long int B);

int main(){
	long long int A, B;
	scanf("%lld %lld", &A, &B);
	int gcd = GCD(A, B);
	for(int i =0; i < gcd; i++)
		printf("1");
}

long long int GCD(long long int A, long long int B){
	if(B==0)
		return A;
	return GCD(B, A%B);
}