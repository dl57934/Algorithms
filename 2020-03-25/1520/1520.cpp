#include <cstdio>
#include <string.h>

int M, N;
int map[502][502];
int dp[502][502];

int xPos[4] = {-1, 0, 1, 0};
int yPos[4] = {0, -1, 0, 1};

void input();
int dfsDP(int y, int x);

int main(){
	input();
	printf("%d", dfsDP(0, 0));
}

void input(){
	scanf("%d %d", &M, &N);

	for(int y = 0; y < M; y++)
		for(int x = 0; x < N; x++)
			scanf("%d", &map[y][x]);
	memset(dp, -1, sizeof(dp));
}

int dfsDP(int y, int x){
	if(dp[y][x] != -1)
		return dp[y][x];
	if(y == M-1 && x == N-1)
		return 1;

	if(dp[y][x] == -1){
		dp[y][x] = 0;
		for(int i = 0; i < 4; i++){
			int ay = y + yPos[i];
			int ax = x + xPos[i];
			if(ay >= 0 && ax >= 0 && ay <= M-1 && ax <= N-1 && map[y][x] > map[ay][ax]){
				dp[y][x] += dfsDP(ay, ax);
			}
		}
	}
	return dp[y][x];
}