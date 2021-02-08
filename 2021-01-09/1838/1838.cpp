#include <cstdio>

pair<int, int> num[500002];
int resultNum;

void mergeSort(int start, int end);
void merge(int start, int end, int mid);

int main(){
	int N, mainNum;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++){
		scanf("%d", &mainNum);
	}

	mergeSort(1, N);
	
	printf("%d", resultNum);
}

void mergeSort(int start, int end){

	if(start < end){
		int mid = (start + end)/2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, end, mid);
	}
}


void merge(int start, int end, int mid){
	int part1 = start, part2 = mid+1; 
	int index = start;

	int temp[500002];

	for(int i = start; i <= end; i++){
		temp[i] = num[i];
	}

	while(part1 <= mid && part2 <= end){
		if(temp[part1] < temp[part2]){
			num[index] = temp[part1];
			part1++;
		}else{
			num[index] = temp[part2];
			part2++;
		}
		index++;
	}

	printf("%d %d %d\n", part1, mid, part2);

	for(int i = 0; i <= mid - part1; i++){
		num[index + i] = temp[part1 + i];
	}
}