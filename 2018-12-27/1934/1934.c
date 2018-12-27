#include <stdio.h>

int A,B;
int LCM(int A, int B, int GSD);
int GSD(int A, int B);

int main(T){
	scanf("%d", &T);
	int temp=0;
	
	for(int i = 0; i < T;i ++){
		scanf("%d %d", &A, &B);
		if(A < B){
			temp = A;
			A = B;
			B = temp;
		}
		printf("%d\n", LCM(A, B, GSD(A, B)));
	}
}

int LCM(int A, int B, int GSD){
	return (A*B)/GSD;
}

int GSD(int A, int B){
	if(B == 0)
		return A;
	return GSD(B, A%B);
}