#include <stdio.h>

int arr[1002];

void quicksort(int start, int end);
int partition(int start, int end);
void swap(int A, int B);
void input(int N);

int main(){
	int N;
	scanf("%d", &N);
	input(N);
	quicksort(0, N-1);
	for(int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}

void input(int N){
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
}

void quicksort(int start, int end){
	if(start < end){
		int part = partition(start, end);
		quicksort(start, part-1);
		quicksort(part, end);
	}
}
int partition(int start, int end){
	int pivot = arr[(start+end)/2];
	while(start<=end){
		while(arr[start] < pivot)start++;
		while(arr[end] > pivot)end--;
		if(start <= end){
			swap(start, end);
			start++;
			end--;
		}
	}
	return start;
}
void swap(int A, int B){
	int temp = arr[A];
	arr[A] = arr[B];
	arr[B] = temp;
}