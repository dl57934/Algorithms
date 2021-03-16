#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;

pair<int, int> arr[500002];

void mergeSort(int start, int end);
void merge(int start, int mid, int end);

int main(){
	int N;
	int number;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &number);
		arr[i] = make_pair(number, i);
	}
	mergeSort(0, N-1);
	
	int maxNum = 0;

	for(int i = 0; i < N; i++){
		if(arr[i].second - i > maxNum)
			maxNum = arr[i].second - i;
	}

	printf("%d", maxNum+1);
}	



void mergeSort(int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end){
	pair<int, int> temp[500002];
	int part1 = start, index = start, part2 = mid+1;

	for(int i = start; i <= end; i++)
		temp[i] = arr[i];

	while(part1 <= mid && part2 <= end){
		if(temp[part1].first > temp[part2].first){
			arr[index] = temp[part2];
			part2++;
		}else{
			arr[index] = temp[part1];
			part1++;
		}
		index++;
	}

	for(int i = 0; i <= mid - part1; i++){
		arr[index + i] = temp[part1 + i];
	}
}

