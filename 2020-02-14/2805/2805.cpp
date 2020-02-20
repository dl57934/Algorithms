#include <stdio.h>
#include <algorithm>

using namespace std;
long long N, M;
long long arr[1000002];
long long length = 0;

void binarySearch(long long start, long long end);

int main(){
	scanf("%lld %lld", &N, &M);

	for(int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	binarySearch(1, *max_element(arr, arr+N));

	printf("%lld", length);
}

void binarySearch(long long start, long long end){
	while(start <= end){
		long long sum = 0;
		long long mid = (start+end)/2;

		for(int i = 0; i < N; i++){
			if(arr[i] - mid >= 0)
				sum+=(arr[i] - mid);
		}

		if(sum >= M){
			if(mid > length)
				length = mid;
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
}