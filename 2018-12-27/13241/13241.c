#include <stdio.h>

void BiggerNumber(long long int *A, long long int *B);
long long int LCM(long long int A, long long int B, long long int GSD);
long long int GSD(long long int A, long long int B);

int main(){
	long long int A, B;
	scanf("%lld %lld", &A, &B);
	BiggerNumber(&A, &B);

	printf("%lld", LCM(A, B, GSD(A,B)));

}
void BiggerNumber(long long int *A, long long int *B){
	long long int temp;
	if(*B > *A){
		temp = *A;
		*A = *B;
		*B = temp;
	}
}


long long int LCM(long long int A, long long int B, long long int GSD){
	return (A*B)/ GSD;
}
long long int GSD(long long int A, long long int B){
	if(B == 0)
		return A;
	return GSD(B, A%B);
}