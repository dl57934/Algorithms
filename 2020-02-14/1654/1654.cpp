#include <stdio.h>
#include <algorithm>

using namespace std;
long long arr[1000002];
long long maxLength = 0;
long long K, N;
void binarySearch(long long start, long long end, long long findLine);

int main(){
	scanf("%lld %lld", &N, &K);

	for(int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);
	long long maxElement = *max_element(arr, arr+N);
	binarySearch(1, maxElement, K);
	printf("%lld", maxLength);
}

void binarySearch(long long start, long long end, long long findLine){

	while(start <= end){
		long long mid = (start+end)/2;
		long long sum = 0;
		for(int i = 0; i < N; i++){
			sum+=arr[i]/mid;
		}

		if(sum >= findLine){
			if(maxLength < mid)
				maxLength=mid;
			start = mid+1;
		}else{
			end = mid-1;
		}
	}
}