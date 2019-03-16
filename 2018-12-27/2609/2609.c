#include <stdio.h>


void changeBigNumber(int *A, int *B);
int GSD(int A, int B);
int LCM(int A, int B, int GSD);

int main(){
	int A, B;
	int gsd;
	scanf("%d %d", &A, &B);
	
	if(A < B)
		changeBigNumber(&A, &B);
	gsd = GSD(A,B);
	printf("%d\n",gsd);
	printf("%d", LCM(A,B, gsd));
}


void changeBigNumber(int *A, int *B){
	int temp;
	
	temp = *A;
	*A = *B;
	*B = temp;
}

int LCM(int A, int B, int GSD){
	return (A*B)/GSD;
}

int GSD(int A, int B){
	if(B==0)
		return A;
	return GSD(B, A%B);
}

