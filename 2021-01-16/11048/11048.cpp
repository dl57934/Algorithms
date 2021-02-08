#include <cstdio>
#include <algorithm>

using namespace std;

int map[1002][1002], dp[1002][1002];
int N, M;

void solve();

int main(){
	scanf("%d %d", &N, &M);
	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= M; x++)
			scanf("%d", &map[y][x]);
	solve();
}

void solve(){
	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= M; x++){
			dp[y][x] = max(dp[y-1][x], max(dp[y][x-1], dp[y-1][x-1])) + map[y][x];
		}

	printf("%d", dp[N][M]);
}