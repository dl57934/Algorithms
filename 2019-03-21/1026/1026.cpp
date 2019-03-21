#include <cstdio>

int A[101];
int B[101];

void mergesort(int start, int end);
void merge(int start, int mid, int end);
void quicksort(int start, int end);
int partition(int start, int end);
void swap(int a, int b);

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for(int i = 0; i < N; i++)
		scanf("%d", &B[i]);

	mergesort(0, N-1);
	quicksort(0, N-1);

	int sum = 0;

	for(int i = 0; i < N; i++)
		sum+=A[i]*B[i];

	printf("%d", sum);
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
	int temp[101];
	for(int i = start; i <= end; i++)
		temp[i] = A[i];

	int part1 =start, index = start;
	int part2 = mid+1;

	while(part1<= mid && part2 <= end){
		if(temp[part1] < temp[part2]){
			A[index] = temp[part1];
			part1+=1;
		}else {	
			A[index] = temp[part2];
			part2+=1;
		}
		index+=1;
	}

	for(int i = 0; i <= mid-part1; i++)
		A[index+i] = temp[part1+i];
	
}

void quicksort(int start, int end){
	if(start < end){
		int mid = partition(start, end);
		if(start <mid-1)
			quicksort(start, mid-1);
		if(mid < end)
			quicksort(mid, end);
	}
}

int partition(int start, int end){
	int pivot = B[(start+end)/2];
	while(start<=end){
		while(pivot < B[start])start++;
		while(pivot > B[end]) end--;
		if(start <= end){
			swap(start, end);
			start++;
			end--;
		}
	}

	return start;
}



void swap(int a, int b){
	int temp = B[a];
	B[a] = B[b];
	B[b] = temp;
}

