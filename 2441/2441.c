#include <stdio.h>

main(N){
	scanf("%d", &N);

	for (int i =0 ;i<N;i++){
		for (int j = i; j>0;j--){
			printf(" ");
		}
		for(int k = i; k < N; k++){
			printf("*");
		}
		printf("\n");
	}
}