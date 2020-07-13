#include <cstdio>
#include <queue>

using namespace std;
int map[1002][1002];
int check[1002][1002][3];
int distances[1002][1002][3];
int ypos[4] = {1, -1, 0, 0};
int xpos[4] = {0, 0, 1, -1};
queue <pair<int, pair<int, int> > > qu;

int N, M;
void input();
void bfs();

int main(){
	input();
	bfs();

	if(distances[N][M][0] == 0  && distances[N][M][1] == 0)
		printf("-1");
	else if(distances[N][M][0] == 0){
		printf("%d", distances[N][M][1]);
	}else if(distances[N][M][1] == 0){
		printf("%d", distances[N][M][0]);
	}else if(distances[N][M][0] > distances[N][M][1])
	printf("%d", distances[N][M][1]);
	else 
		printf("%d", distances[N][M][0]);
}

void input(){
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf("%1d", &map[y][x]);
		}
	}
}

void bfs(){  // 1 부술 수 있음, 0지나갈 수 있음
	qu.push(make_pair(1, make_pair(1, 1)));
	check[1][1][1] = 1;
	distances[1][1][1] = 1;
	while(!qu.empty()){
		int canWin = qu.front().first;
		pair<int, int> now  = qu.front().second;
		qu.pop();
		for(int i = 0; i < 4; i++){
			int nextY = now.first + ypos[i];
			int nextX = now.second + xpos[i];

			if(nextY >= 1 && nextY <= N && nextX >=1 && nextX <= M){
				if(map[nextY][nextX] == 0 && check[nextY][nextX][canWin] == 0){
					check[nextY][nextX][canWin] = 1;
					distances[nextY][nextX][canWin] = distances[now.first][now.second][canWin] + 1;
					qu.push(make_pair(canWin, make_pair(nextY, nextX)));
				}else if(map[nextY][nextX]==1 && check[nextY][nextX][1] == 0 && canWin){
					check[nextY][nextX][0] = 1;
					distances[nextY][nextX][0] = distances[now.first][now.second][canWin] + 1;
					qu.push(make_pair(0, make_pair(nextY, nextX)));
				}
			}
		}
	}
}