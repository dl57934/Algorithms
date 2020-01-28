#include <cstdio>
#include <math.h>

long long dp[102][12];

int main(){
	int  N;
	scanf("%d", &N);

	for(int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for(int i = 2; i <= N; i++){
		dp[i][0] = dp[i-1][1];
		for(int j = 1; j < 10; j++)
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
	}

	long long result= 0;
	for(int i = 0; i < 10; i++){
		result += dp[N][i];
	}

	printf("%lld", result%1000000000);
}