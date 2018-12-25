#include <stdio.h>

int main(N){
	scanf("%d", &N);
	for (int i = 1; i<=N;i++){
		for (int j = N; j > i; j--){
			printf(" ");
		}
		for (int k = 0;k < i; k++){
			printf("*");
		}
		printf("\n");
	}
}