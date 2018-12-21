#include <stdio.h>

main(){
	int X, N;
	int count = 0;
	int result[10000] = {0,};
	int inputValue = 0;
	scanf("%d %d", &X, &N);
	for(int i = 0; i < X;i++){
		scanf("%d", &inputValue);
		if(inputValue < N){
			result[count] = inputValue;
			count++;
		}
		
	}
	for(int i = 0; i< count;i++)
		printf("%d ",result[i]);
}