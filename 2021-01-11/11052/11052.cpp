#include <cstdio>
#include <algorithm>

using namespace std;

int value[1002], dp[1002];

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
		scanf("%d", &value[i]);

	for(int i = 1; i <= N; i++){
		for(int baseNum = 1; baseNum <= i/2; baseNum++){
			dp[i] = max(dp[baseNum] + dp[i - baseNum], dp[i]);
		}
		dp[i] = max(dp[i], value[i]);
	}

	printf("%d", dp[N]);
}