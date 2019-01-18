#include <stdio.h>

void quickSort(int start, int end);
int partition(int start, int end);
void swap(int start, int end);

int arr[1002];

int main(){
	int N;
	
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	quickSort(0, N-1);

	for(int i =0; i <N;i++)
		printf("%d\n", arr[i]);
	
}

void quickSort(int start, int end){
	int part = partition(start, end);
	if(start < part-1)
		quickSort(start, part-1);
	if(part<end)
		quickSort(part, end);
}

int partition(int start, int end){
	int pivot = arr[(start+end)/2];

	while(start<=end){
		while(arr[start] < pivot) start++;
		while(arr[end] > pivot) end--;
		if(start <= end){
			swap(start, end);
			start++;
			end--;
		}
	}
	return start;
}

void swap(int start, int end){
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
}