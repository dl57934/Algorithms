#include <stdio.h>

void mergesort(int start, int end);
void merge(int start, int end, int mid);
int binarySearch(int target, int start, int end);
int input(int arr[]);

int A[100002];
int targets[100002];
int result[100002];
int main(){
	int size = input(A);
	mergesort(0, size-1);
	int targetSize = input(targets);
	for(int i = 0; i < targetSize; i++)
		printf("%d\n", binarySearch(targets[i], 0, size));
}

int input(int arr[]){
	int size;
	scanf("%d", &size);
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	return size;
}

void mergesort(int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergesort(start, mid);
		mergesort(mid+1, end);
		merge(start, end, mid);
	}
}
void merge(int start, int end, int mid){
	int temp[100002];
	int index = start, part1 = start;
	int part2 = mid+1;
	for(int i = start; i <= end; i++)
		temp[i] = A[i];

	while(part1<=mid && part2 <= end){
		if(temp[part1] < temp[part2]){
			A[index] = temp[part1];
			part1++;
		}else{
			A[index] = temp[part2];
			part2++;
		}
		index++;
	}

	for(int i = 0; i <= mid-part1; i++)
		A[index+i] = temp[part1+i];
}

int binarySearch(int target, int start, int end){
	while(start <= end){
		int mid = (start+end)/2;
		if(target == A[mid])
			return 1;
		else if(target < A[mid])
			end = mid-1;
		else 	
			start = mid+1;
	}
	return 0;
}

