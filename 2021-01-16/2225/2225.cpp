#include <cstdio>

long long dp[202][202];
int N, K;

int main(){
	scanf("%d %d", &N, &K);

	for(int n = 1; n <= N; n++){
		for(int k = 1; k <= K; k++){
			if(n == 1)
				dp[n][k] = k;
			else{
				dp[n][k] = (dp[n][k-1] + dp[n-1][k]) % 1000000000;
				dp[n][k] %= 1000000000;
			}
		}
	}

	printf("%lld", dp[N][K]);
}