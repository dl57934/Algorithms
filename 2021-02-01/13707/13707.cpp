#include <cstdio>
#define ll long long

ll dp[5002][5002];

int main(){
	ll K, N;
	scanf("%lld %lld", &N, &K);

	for(int n = 1; n <= 5000; n++){
		for(int k = 1; k <= 5000; k++){
			if(n == 1){
				dp[n][k] = k;
			}else{
				dp[n][k] = (dp[n-1][k] + dp[n][k-1] ) % 1000000000;
				dp[n][k] %= 1000000000;
			}
		}
	}

	printf("%lld", dp[N][K]%1000000000);
}