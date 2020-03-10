#include <cstdio>

int N, K;

int binary_search(int start, int end);

int main(){
	scanf("%d %d", &N, &K);
	printf("%d", binary_search(1, K));
}
int binary_search(int start, int end){
	if(start > end)
		return start;
	int cnt = 0;
	int mid = (start + end) /2;
	for(int i = 1; i <= N; i++)
		cnt += N < mid/i? N : mid/i;

	if(cnt < K){
		return binary_search(mid+1, end);
	}else{
		return binary_search(start, mid-1);
	}
}