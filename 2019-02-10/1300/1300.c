#include <stdio.h>

void quicksort(int start, int end);
int partition(int start, int end);
void swap(int a, int b);

int A[100002][100002];

int main(){
	int N, K;
	int i = 1, j = 1;
	scanf("%d %d", &N, &K);
	for(int m = 0; m < N*N; m++){
		A[m] = i*j;
		j+=1;
		if(j == N){
			j=1;
			i+=1;
		}
	}
	quicksort(0, N*N-1);
	
	printf("%d", A[K]);
}

void quicksort(int start, int end){
	if(start < end){
		int part = partition(start, end);
		quicksort(start, part-1);
		quicksort(part, end);
	}
}
int partition(int start, int end){
	int pivot = A[(start+end)/2];
	while(start <= end){
		while(pivot > A[start]) start++;
		while(pivot < A[end]) end--;
		if(start <= end){
			swap(start, end);
			start++;
			end--;
		}
	}
	return start;
}
void swap(int a, int b){
	int temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}