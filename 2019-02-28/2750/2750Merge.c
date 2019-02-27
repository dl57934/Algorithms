#include <stdio.h>

int arr[1003];

void input(int N);
void output(int N);
void mergesort(int start, int end);
void merge(int start,int mid, int end);

int main(){
	int N;
	scanf("%d", &N);
	input(N);
	mergesort(0, N-1);
	output(N);
}

void input(int N){
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
}

void output(int N){
	for(int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}

void mergesort(int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		mergesort(start, mid);
		mergesort(mid+1, end);
		merge(start, mid, end);
	}
}
void merge(int start,int mid, int end){
	int temp[1002];
	for(int i = start; i <= end; i++)
		temp[i] = arr[i];
	int part1 = start, index = start;
	int part2 = mid+1;
	while(part1<=mid && part2<=end){
		if(temp[part1] < temp[part2]){
			arr[index] = temp[part1];
			part1++;
		}else{
			arr[index] = temp[part2];
			part2++;
		}
		index++;
	}

	for(int i = 0; i <= mid-part1; i++)
		arr[i+index] = temp[i+part1]; 
}