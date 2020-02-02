#include <stdio.h>
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
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[1] + arr[0], arr[1] + arr[2]);

	for(int i = 3; i < N; i++)
		dp[i] = max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]);

	printf("%d", dp[N-1]);
}