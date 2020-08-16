#include <cstdio>
#include <math.h>

int isPrime[4000002], arr[4000002];

int setPrimeNumber(int num);
int discoverCount(int N);

int main(){
	int index = 0, N;
	for(int sub = 2; sub <= 4000000; sub++){
		if(isPrime[sub] == 1)continue;
		for(int multiNum = sub + sub; multiNum <= 4000000; multiNum+=sub){
			isPrime[multiNum] = 1;
		}
	}

	for(int sub = 2; sub <= 4000000; sub++){
		if(isPrime[sub] == 0){
			arr[index] = sub;
			index++;
		}
	}

	scanf("%d", &N);

	printf("%d", discoverCount(N));
}

int discoverCount(int N){
	int start = 0, end = 0;
	int count = 0, subSum = 0;

	while(end <= N){
		if(subSum < N){
			subSum+=arr[end];
			end++;
		}else if(subSum >= N){
			subSum-=arr[start];
			start++;
		}

		if(N == subSum)
			count++;
	}

	return count;
}