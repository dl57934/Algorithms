#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int count = 0;
int dp[1000002];
int main(){
	scanf("%d", &N);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for(int i = 4; i <= N; i++){
		if(i%3==0){
			if(i%2==0)
				dp[i] = min(min(dp[i/2] + 1, dp[i/3] + 1), dp[i-1] + 1);
			else
				dp[i] = min(dp[i-1] + 1, dp[i/3] + 1);
		}else if(i%2==0){
			dp[i] = min(dp[i-1] + 1,dp[i/2] + 1); 
		}else{
			dp[i] = dp[i-1] + 1;
		}
	}
	printf("%d", dp[N]);
}