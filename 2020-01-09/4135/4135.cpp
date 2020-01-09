#include <stdio.h>

int squared(int num);

int A, B, C;

int main(){
	for(;;){
		scanf("%d %d %d", &A, &B, &C);
		if( A + B + C==0)
			break;
		if(squared(A) + squared(B) == squared(C) || squared(C) + squared(B) == squared(A) || squared(A) + squared(C) == squared(B) )
			printf("right\n");
		else
			printf("wrong\n");
	}
	
}

int squared(int num){
	return num * num;
}

