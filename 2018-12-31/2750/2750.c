#include <stdio.h>

int bubbleArr[1001];

void bubbleSort(int N);
void reverseNumber(int i, int j);

int main(N){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &bubbleArr[i]);
	bubbleSort(N);
	for(int i = 0; i < N; i++)
		printf("%d\n", bubbleArr[i]);
}

void bubbleSort(int N){
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++)
			if(bubbleArr[i] > bubbleArr[j])
				reverseNumber(i, j);
	}
}

void reverseNumber(int i, int j){
	int temp;
	temp = bubbleArr[i];
	bubbleArr[i] = bubbleArr[j];
	bubbleArr[j] = temp;
}