#include <cstdio>
#include <queue>
#include <string.h>

int M, N;

int map[502][502];
int dp[502][502];
int visit[502][502];
int result = 0;

int xPos[4] = {-1, 0, 1, 0};
int yPos[4] = {0, 1, 0, -1};

void input();
int dpDFS(int y, int x);
void getDestination(int y, int x);

int main(){
	input();
	
	printf("%d\n", dpDFS(0, 0));

	// for(int y = 0; y < M; y++){
	// 	for(int x = 0; x < N; x++){
	// 		printf("%3d ", dp[y][x]);
	// 	}
	// 	printf("\n");
	// }
}

void input(){
	scanf("%d %d", &M, &N);
	for(int y = 0; y < M; y++)
		for(int x = 0; x < N; x++)
			scanf("%d", &map[y][x]);

	memset(dp, -1, sizeof(dp));
}

int dpDFS(int y, int x){
	if(dp[y][x] != -1)
		return dp[y][x];

	if(y == M-1 && x == N-1)
		return 1;
	if(dp[y][x] == -1){
		dp[y][x] = 0;
		for(int i = 0; i < 4; i++){
		int ay = y + yPos[i];
		int ax = x + xPos[i];
			if(ay >= 0 && ax >= 0 && ay < M && ax < N && map[ay][ax] < map[y][x]){
				dp[y][x] += dpDFS(ay, ax);
			}
		}	
	}
	
	return dp[y][x];
}
