#include <stdio.h>

long long arr[1002][1002]={0,};

long long ncr(int N, int K);

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%lld", ncr(N, K));
}

long long ncr(int N, int K){
	if(N==K || K==0)
		return 1;
	else {
		if(arr[N][K] == 0)
			arr[N][K] = (ncr(N-1, K-1)%10007 + ncr(N-1, K)%10007)%10007;
		return arr[N][K]%10007;
	}
}