#include <cstdio>
#include <algorithm>
long long arr[10002];
long long dp[10002];

using namespace std;

int main(){
	int N;

	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
		scanf("%lld", &arr[i]);

	dp[1] = arr[1];
	dp[2] = arr[2] + arr[1];

	for(int i = 3; i <= N; i++){
		dp[i] = max(arr[i-1] + dp[i-3], dp[i-2]) + arr[i];
		dp[i] = max(dp[i-1], dp[i]);
	}

	
	printf("%lld", *max_element(dp, dp+N+1));
}