#include <cstdio>
#include <algorithm>

using namespace std;

int sum[50002], passenger[50002];
int dp[5][50002], limit, N;

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &passenger[i]);
		sum[i] = sum[i-1] + passenger[i];
	}

	scanf("%d", &limit);

	for(int nowTrain = 1; nowTrain <= 3; nowTrain++){
		for(int room = (nowTrain -1)* limit + 1; room < N; room++){
		 	dp[nowTrain][room] = max(dp[nowTrain][room-1], (room-limit < 0? 0 :dp[nowTrain-1][room-limit]) + sum[room] -  (room-limit < 0? 0 : sum[room-limit]));
		}
	}

	printf("%d", dp[3][N-1]);
}