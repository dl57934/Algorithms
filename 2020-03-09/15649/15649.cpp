#include <cstdio>
#include <algorithm>

int N, M;
int nArr[1000002], mArr[100002];
int checkArr[1000002];

void mergeSort(int start, int end);
void merge(int start, int mid, int end);
void binarySearch(int start, int end, int findNumber, int index);

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &nArr[i]);
	scanf("%d", &M);
	for(int i = 0; i < M; i++)
		scanf("%d", &mArr[i]);
}

int main(){
	input();
	mergeSort(0, N-1);
	for(int i = 0; i < M; i++)
		binarySearch(0, N, mArr[i], i);
	for(int i = 0; i < M;i++)
		printf("%d\n", checkArr[i]);
}


void mergeSort(int start, int end){
	if(start < end){
		int mid = (start + end) / 2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end){
	int part1 = start, part2 = mid+1;
	int index = start;

	int temp[100002];
	for(int i = start; i <= end; i++)
		temp[i] = nArr[i];

	while(part1 <= mid && part2<=end){
		if(temp[part1] < temp[part2]){
			nArr[index] = temp[part1];
			part1++;
		}else{
			nArr[index] = temp[part2];
			part2++;
		}	
		index+=1;
	}

	for(int i = 0; i <= mid-part1; i++)
		nArr[index+i] = temp[i+part1];
}

void binarySearch(int start, int end, int findNumber, int index){
	int mid = (start + end) /2;

	if( start > end){
		checkArr[index] = 0;
		return ;
	}

	if(findNumber == nArr[mid]){
		checkArr[index] = 1;
		return ;
	}

	if(nArr[mid] < findNumber)
		binarySearch(mid+1, end, findNumber, index);
	if(nArr[mid] > findNumber)
		binarySearch(start, mid-1, findNumber, index);
}