#include <stdio.h>

int num[1002];

void input(int N);
void quicksort(int start, int end);
int partition(int start, int end);
void swap(int start, int end);
void mergesort(int start, int end);
void merge(int start, int mid, int end);
void output();

int main(){
	int N;
	scanf("%d", &N);
	input(N);
	mergesort(0, N-1);
	output(N);
}

void input(int N){
	for(int i = 0; i<N; i++)
		scanf("%d", &num[i]);
}



void mergesort(int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergesort(start, mid);
		mergesort(mid+1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end){
	int temp[end+1];
	int part1 = start;
	int part2 = mid+1;
	int index = start;

	for(int i = start; i <= end; i++)
		temp[i] = num[i];

	while(part1<=mid && part2<=end){
		if(temp[part1] < temp[part2]){
			num[index] = temp[part1];
			part1++;
		}else{
			num[index] = temp[part2];
			part2++;
		}
		index++;
	}
	for(int i = 0; i <= mid-part1; i++)
		num[index+i] = temp[part1+i];
}

void quicksort(int start, int end){
	int part = partition(start, end);
	if(start < part-1)
		quicksort(start, part-1);
	if(part < end)
		quicksort(part, end);
}

int partition(int start, int end){
	int pivot = num[(start+end)/2];
	while(start<=end){
		while(pivot > num[start])start++;
		while(pivot < num[end])end--;
		if(start<=end){
			swap(start, end);
			start++;
			end--;
		}
	}
	return start;
}

void swap(int start, int end){
	int temp = num[start];
	num[start] = num[end];
	num[end] = temp;
}

void output(int N){
	for(int i = 0; i<N; i++)
		printf("%d\n", num[i]);
}