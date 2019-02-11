#include <stdio.h>

#define ll long long

int Ai[5000000];
int temp[5000000];
void mergesort(int start, int end);
void merge(int start, int mid, int end);

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%d", &Ai[i]);
	mergesort(0, N-1);
	printf("%d", Ai[K-1]);
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
	temp[5000000];

	for(int i = start; i <= end; i++)
		temp[i] = Ai[i];
	int part1 = start, index = start;
	int part2 = mid+1;

	while(part1 <= mid && part2 <=end){
		if(temp[part1] < temp[part2]){
			Ai[index] = temp[part1];
			part1++;
		}else{
			Ai[index] = temp[part2];
			part2++;
		}
		index++;
	}

	for(int i =0; i <=mid-part1; i++)
		Ai[i+index] = temp[part1+i];
}