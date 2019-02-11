#include <stdio.h>

int person[1002];

void mergeSort(int start, int end);
void merge(int start, int mid, int end);

int main(){
	int N, result=0, save=0;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &person[i]);
	mergeSort(0, N-1);

	for(int i = 0; i < N; i++){
		save+=person[i];
		result+=save; 
	}
	printf("%d", result);
	
}

void mergeSort(int start, int end){
	if( start < end){
		int mid = (start+end)/2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, mid, end);
	}
}
void merge(int start, int mid, int end){
	int temp[1003];
	for(int i = start; i <= end; i++)
		temp[i] = person[i];

	int part1=start, index=start;
	int part2 = mid+1;
	while(part1 <= mid && part2 <= end){
		if(temp[part1] <= temp[part2]){
			person[index] = temp[part1];
			part1++;
		}else{
			person[index] = temp[part2];
			part2++;
		}
		index++;
	}

	for(int i = 0; i <= mid-part1; i++)
		person[index+i] = temp[part1+i];
}