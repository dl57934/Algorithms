#include <stdio.h>

int arr[53];

void mergesort(int start, int end);
void merge(int start, int mid, int end);

int main(){
	int N;
	scanf("%d", &N);

	for(int i =0; i < N; i++)
		scanf("%d", &arr[i]);
	mergesort(0, N-1);
	int first = arr[0], last = arr[N-1];
	printf("%d\n", first*last);
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
	int temp[56];
	for (int i = start; i <= end; i++)
		temp[i] = arr[i];
	int part1 = start, part2 = mid+1;
	int index = start;

	while(part1 <= mid && part2 <= end){
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
		arr[index+i] = temp[part1+i];
}