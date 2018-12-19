#include <stdio.h>

int main(N){
	int result = 0;
	int arr[10] = {0,};
	char word;
	scanf("%d", &N);
		getchar();
	for (int i = 0; i < N; i++){
		word = getchar();
		arr[word-'0'] += 1;
	}

	for (int i = 1; i<10;i++)
		result += arr[i] * i;
	printf("%d", result);
}