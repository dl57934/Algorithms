#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

int map[100002][3];
int dp[100002][3];

void solve();
void dpSolve();

int main(){
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; i++)
		solve();
}

int N;
void solve(){
	memset(map, 0, sizeof(map));
	memset(dp, 0, sizeof(dp));

	scanf("%d", &N);

	for(int j = 0; j < 2; j++)
		for(int i = 1; i <= N; i++)
			scanf("%d", &map[i][j]);
	
	dp[1][0] = map[1][0];	
	dp[1][1] = map[1][1];

	dpSolve();

	printf("%d\n", max(dp[N][0], dp[N][1]));
}

void dpSolve(){
	for(int i = 2; i <= N; i++){
		dp[i][1] = max(dp[i-1][0], dp[i-2][0]) + map[i][1];
		dp[i][0] = max(dp[i-1][1], dp[i-2][1]) + map[i][0];
	}
}