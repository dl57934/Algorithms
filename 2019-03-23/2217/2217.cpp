#include <cstdio>

using namespace std;

int arr[100004];

void mergesort(int start, int end);
void merge(int start, int mid, int end);

int main(){
	int N;
	int rope, minRope;
	int max = 0;
	int now = 0;
	int ropes;
	int count = 0;

	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	mergesort(0, N-1);

	max = arr[0];
	ropes = N;
	for(int i = 0; i < N; i++){
		if(max < arr[i] * (N-i))
			max = arr[i] * (N-i);
	}
	printf("%d", max);
}

void mergesort(int start, int end){
	if(start < end){
		int mid =(start + end)/2;
		mergesort(start, mid);
		mergesort(mid+1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end){
	int temp[100004];
	for(int i = start; i <=end; i++ )
		temp[i] = arr[i];

	int index = start, part1 = start;
	int part2 = mid+1;

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
		arr[i+index] = temp[part1+i]; 
}






