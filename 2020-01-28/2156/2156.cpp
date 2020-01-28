#include <cstdio>
#include <algorithm>

using namespace std;

int N;
long long grapeAlchol[10003];
long long dp[100003] = {0, };

int main(){
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
		scanf("%lld", &grapeAlchol[i]);

	dp[1] = grapeAlchol[1];
	dp[2] = grapeAlchol[2] + dp[1];

	for(int i = 3; i <= N; i++){
		dp[i] = max(grapeAlchol[i-1] + dp[i-3] + grapeAlchol[i], dp[i-2] + grapeAlchol[i]);
		dp[i] = max(dp[i-1], dp[i]);
	}

	printf("%lld", dp[N]);
}


