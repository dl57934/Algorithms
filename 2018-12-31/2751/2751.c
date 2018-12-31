#include <stdio.h>

void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void swap(int arr[], int start, int end);

#define LimitNumber 1000001

int main(N){
	scanf("%d", &N);
	int arr[LimitNumber] = {0,};
	for(int i=0; i < N; i++)
		scanf("%d", &arr[i]);

	quickSort(arr, 0, N-1);
	
	for(int i=0; i < N; i++)
		printf("%d\n", arr[i]);
}

void quickSort(int arr[], int start, int end){
	int part2 = partition(arr, start, end);
	if(start < part2-1)
		quickSort(arr, start, part2-1);
	if(end > part2)
		quickSort(arr, part2, end);
}

int partition(int arr[], int start, int end){
	int pivot = arr[(start+end)/2];
	while(start <= end){
		while(arr[start] < pivot) start++; 
		while(pivot < arr[end]) end--;
		if(start <= end){
			swap(arr, start, end);
			start++;
			end--;
		}
	}
	return start;
}

void swap(int arr[], int start, int end){
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
}