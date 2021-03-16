#include <cstdio>

int arr[1000002];
void mergeSort(int start, int end);
void merge(int start, int mid, int end);

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	mergeSort(0, N-1);
	for(int i = 0; i < N; i++){
		printf("%d\n", arr[i]);
	}
}

void mergeSort(int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		mergeSort(start, mid);
		mergeSort(mid + 1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end){
	int temp[1000002];
	int part1 = start, part2 = mid + 1;
	int index = start;
	for(int i = start; i <= end; i++)
		temp[i] = arr[i];

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

	for(int i = 0; i <= mid - part1; i++){
		arr[index + i] = temp[part1+i];
	}
}