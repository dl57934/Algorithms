#include <cstdio>
#define ll long long

ll arr[4000002], isPrime[4000002];

void setPrime(){
	
	for(int i = 2; i <= 4000000; i++){
		for(int num = i + i; num <= 4000000; num+=i)
			isPrime[num] = 1;
	}
	int index = 0;
	for(int prime = 2; prime <= 4000000; prime++)
		if(isPrime[prime] == 0){
			arr[index] = prime;
			index++;
		}
}

ll sumCount(int N){
	int start = 0, end = 0;
	ll subSum = 0, count = 0;
	while(end <= N){
		if(subSum < N){
			subSum += arr[end];
			end++;
		}else if(subSum >= N){
			subSum -= arr[start];
			start++;
		}

		if(subSum == N)
			count++;
	}

	return count;
}

int main(){
	int  N;
	scanf("%d", &N);
	setPrime();
	printf("%lld", sumCount(N));
}