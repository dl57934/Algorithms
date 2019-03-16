#include <stdio.h>

int arr[10002] = {0,};

void setArray(int N);
void printArray(int N);

int main(N){
	scanf("%d", &N);
	setArray(N);
	printArray(N);
}

void setArray(int N){
	int arrayNum;
	for(int i = 0; i < N; i++){
		scanf("%d", &arrayNum);
		arr[arrayNum]+=1;
	}
}

void printArray(int N){
	for(int i = 1; i < 10001; i++){
		for(int j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}
}