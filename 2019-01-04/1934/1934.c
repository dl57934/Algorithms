#include <stdio.h>

int LCM(int gcd, int A, int B){
	return (A * B)/gcd;
}

int GCD(int big, int small){
	if(small == 0)
		return big;
	return GCD(small, big%small);
}

void swap(int *A, int *B){
	int temp = *A;
	*A = *B;
	*B = temp;
}

int main(){
	int T;
	int A, B;
	int gcd;
	scanf("%d", &T);
	for(int i =0; i < T; i++){
		scanf("%d %d", &A, &B);
		if(B > A)
			swap(&A, &B);
		gcd = GCD(A, B);
		printf("%d\n", LCM(gcd, A, B));
	}
}