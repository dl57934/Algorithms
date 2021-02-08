#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1002];
int dp[1002];
int N;
void solve();

int main(){
	

	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	solve();
}

void solve(){
	for(int i = 0; i < N; i++){
		if(dp[i] == 0)
			dp[i] = arr[i];
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i]){
				dp[i] = dp[j] + arr[i];
			}
		}
	}

	printf("%d", *max_element(dp, dp+N));
}