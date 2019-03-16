#include <stdio.h>

int binarySearch(int start, int end);

int N, K;

int main(){
	scanf("%d %d", &N, &K);
	printf("%d", binarySearch(1, K));
}

int binarySearch(int start, int end){
	if(start > end)
		return start;
	int mid = (start + end)/2;
	int cnt = 0;

	for(int i = 1; i <= N; i++)
		cnt += N < mid/i? N:mid/i;
	if(cnt < K)
		return binarySearch(mid+1, end);
	else
		return binarySearch(start, mid-1);
	
}