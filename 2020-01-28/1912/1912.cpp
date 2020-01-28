#include <cstdio>
#include <algorithm>

using namespace std;
int N;
int arr[100002];
int dp[100002];

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dp[0] = arr[0];

	for(int i = 1; i < N; i++){
		dp[i] = max(dp[i-1]+arr[i], arr[i]);
	}

	printf("%d", *max_element(dp, dp+N));
}