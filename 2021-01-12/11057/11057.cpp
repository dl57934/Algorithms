#include <cstdio>

#define ll long long

int N;
ll dp[1002][12];
ll result;
int main(){
	scanf("%d", &N);

	for(int i = 0; i < 10; i++)
		dp[1][i] = 1;
	

	for(int i = 2; i <= N; i++){
		for(int j = 0; j < 10; j++){
			for(int k = j; k < 10; k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	for(int i = 0; i <= 9; i++)
		result = (result + dp[N][i]) % 10007;


	printf("%lld", result);
}