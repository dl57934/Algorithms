#include <cstdio>
#define ll long long
ll dp[67][10];

void solve();
void init();

int main(){
	int T, N;
	ll result = 0;
	scanf("%d", &T);
	init();
	solve();
	for(int i = 0; i < T; i++){
		result = 0;
		scanf("%d", &N);
		for(int j = 0; j <= 9; j++)
			result += dp[N][j];
		printf("%lld\n", result);
	}
}

void init(){
	for(int i = 0; i <= 9; i++)
		dp[1][i] = 1;
}	

void solve(){
	for(int i = 2; i <= 64; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= j; k++)
				dp[i][j] += dp[i-1][k];
		}
	}
}