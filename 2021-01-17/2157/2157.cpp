#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int N, K, M;
int dp[302][302];
int map[302][302];
vector<int> point[302];
void solve();
void dfs(int start, int visit);

int main(){
	int start, end, weight;
	scanf("%d %d %d", &N, &M, &K);

	for(int y = 1; y <= K; y++ ){
		scanf("%d %d %d", &start, &end, &weight);
		if(end > start){
			if(map[start][end] == 0)
				point[start].push_back(end);
			map[start][end] = max(map[start][end], weight);
		}
	}

	solve();
}

int maxValue;

void solve(){
	for(int nextPoint : point[1])
		dp[nextPoint][2] = max(dp[nextPoint][2], map[1][nextPoint]);
	
	for(int m = 2; m <= M; m++){
		for(int now = 2; now <= N; now++){
			if(dp[now][m] != 0)
			for(auto nextPoint : point[now]){
				dp[nextPoint][m+1] = max(dp[nextPoint][m+1], dp[now][m] + map[now][nextPoint]);
			}
		}
	}

	int maxValue = 0;

	for(int i = 1; i <= M; i++)
		if(maxValue < dp[N][i])
			maxValue = dp[N][i];

	printf("%d", maxValue);
}	
