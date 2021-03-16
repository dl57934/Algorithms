#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int dp[1002];
pair<int, int> map[1002];

void getMaxValue(int now, int time, int value){
	for(int i = now + time; i <= N; i++){
		if(i + map[i].first <= N + 1){
			dp[i] = max(dp[i], map[i].second + value);
			getMaxValue(i, map[i].first, dp[i]);
		}
	}
}

int main(){
	int time, value;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++){
		scanf("%d %d", &time, &value);
		map[i].first = time;
		map[i].second = value;
	}
	
	for(int i = 1; i <= N; i++){
		if(i + map[i].first <= N + 1)
			dp[i] = max(dp[i], map[i].second);
		getMaxValue(i, map[i].first, map[i].second);
	}

	printf("%d", *max_element(dp, dp+N+1));
}

// 1~5일: 50원
// 6일: 10원
// 8~10일: 30원