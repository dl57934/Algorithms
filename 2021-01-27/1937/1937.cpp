#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int map[502][502], dp[502][502], visit[502][502];
int ypos[4]= {0, 1, 0, -1}, xpos[4] = {1, 0, -1, 0};

int dfs(int y, int x, int day);

int N;
int main(){
	
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));

	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			scanf("%d", &map[y][x]);

	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			if(dp[y][x] == -1){
				dfs(y,x, 0);
			}
		}
	}	
	int maxValue = 0;

	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			if(maxValue < dp[y][x]){
				maxValue = dp[y][x];
			}
		}
	}

	printf("%d", maxValue+1);
}

int dfs(int y, int x, int day){
	if(dp[y][x] != -1)
		return dp[y][x];

	for(int i = 0; i < 4; i++){
		int nextY = y + ypos[i], nextX = x + xpos[i];

		if(map[y][x] < map[nextY][nextX] && nextY >= 0 && nextX >= 0 && nextY < N && nextX < N){	
			dp[y][x] = max(dfs(nextY, nextX, day+1) + 1, dp[y][x]);
		}
	}

	return dp[y][x] == -1? 0 : dp[y][x];
}