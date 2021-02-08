#include <cstdio>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int map[1002][1002];
int visited[1002][1002][3] = {0, };
int allDistance[1002][1002][3] = {0, };
int N, M;
int xpos[4] = {0, 1, 0, -1}, ypos[4] = {1, 0, -1, 0};

void solve();

int main(){
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= M; x++)
			scanf("%1d", &map[y][x]);
	solve();
}	


void solve(){
	
	queue <pair<int, pair<int ,int> > > qu;
	qu.push(make_pair(0, make_pair(1, 1)));

	visited[1][1][0] = 1;
	visited[1][1][1] = 1;

	allDistance[1][1][0] = 1; 

	while(!qu.empty()){
		int isBreakWall = qu.front().first;
		pair<int, int> nowPoint = qu.front().second;
		qu.pop();
		
		for(int i = 0; i < 4; i++){
			int newY = nowPoint.first + ypos[i];
			int newX = nowPoint.second + xpos[i];
			if(newY <= N && newY >= 1 && newX <= M && newX >= 1){
				if(map[newY][newX] == 1 && isBreakWall == 0 && visited[newY][newX][1] == 0){
					allDistance[newY][newX][1] = allDistance[nowPoint.first][nowPoint.second][isBreakWall] + 1;
					visited[newY][newX][1] = 1;
					qu.push(make_pair(1, make_pair(newY, newX)));
				}else if(map[newY][newX] == 0 && visited[newY][newX][isBreakWall] == 0){
					visited[newY][newX][isBreakWall] = 1;
					allDistance[newY][newX][isBreakWall] = allDistance[nowPoint.first][nowPoint.second][isBreakWall] + 1;
					qu.push(make_pair(isBreakWall, make_pair(newY, newX)));
				}
			}
		}
	}

	if(allDistance[N][M][0] == 0 && allDistance[N][M][1] == 0){
		printf("-1");
	}else if(allDistance[N][M][0] != 0 && allDistance[N][M][1] != 0){
		printf("%d", min(allDistance[N][M][0], allDistance[N][M][1]));
	}
	else if(allDistance[N][M][0] != 0){
		printf("%d", allDistance[N][M][0]);
	}else if(allDistance[N][M][1] != 0){
		printf("%d", allDistance[N][M][1]);
	}
}