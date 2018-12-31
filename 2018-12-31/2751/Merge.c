#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int temp[], int start, int end);
void merge(int arr[], int temp[], int start, int mid, int end);

#define LimitNumber 1000001

int main(N){
	scanf("%d", &N);
	int arr[LimitNumber] = {0,};
	for(int i=0; i < N; i++)
		scanf("%d", &arr[i]);
	int *temp = (int *)malloc(sizeof(int) * N);
	
	mergeSort(arr, temp, 0, N-1);
	
	for(int i=0; i < N; i++)
		printf("%d\n", arr[i]);
}

void mergeSort(int arr[], int temp[], int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergeSort(arr, temp, start, mid);
		mergeSort(arr, temp, mid+1, end);
		merge(arr, temp, start, mid, end);
	}
}

void merge(int arr[], int temp[], int start, int mid, int end){
	for(int i = start; i <= end; i++)
		temp[i] = arr[i];
	int part1 = start;
	int index = start;
	int part2 = mid+1;
	while(part1<=mid && part2 <=end){
		if(temp[part1] < temp[part2]){
			arr[index] = temp[part1];
			part1++;
		}else {
			arr[index] = temp[part2];
			part2++;
		}
		index++;
	}
	for(int i = 0; i <= mid-part1; i++ )
		arr[index+i] = temp[part1+i];
}