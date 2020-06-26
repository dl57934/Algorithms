#include <cstdio>
#include <queue>

using namespace std;

void input();
void bfs();
void resultPrint();
int N, M;
int map[1002][1002];
queue < pair<pair<int, int>, int> > qu;
int dis[1002][1002][3];
int check[1002][1002][3];
int xpos[4] = {0, 0, -1, 1};
int ypos[4] = {1, -1, 0, 0};


int main(){
	input();
	bfs();
	resultPrint();
}

void input(){
	scanf("%d %d", &N, &M);
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf("%1d", &map[y][x]);
		}
	}
	qu.push(make_pair(make_pair(1, 1),1));
}

// 0은 벽을 부심, 방문할 수 있음
// 1은 벽을 부술 수 있음, 방문 함 
void bfs(){
	dis[1][1][0] = 1;
	dis[1][1][1] = 1;

	check[1][1][0] = 0;
	check[1][1][1] = 0;

	while(!qu.empty()){
		pair<int, int> nowPoint = qu.front().first;
		int canvisit = qu.front().second;
		qu.pop();
		for(int i = 0; i < 4; i++){
			int ny = nowPoint.first + ypos[i];	
			int nx = nowPoint.second + xpos[i];
			if(ny >= 1 && ny <= N && nx >= 1 && nx <= M){
				if(map[ny][nx] == 0 && !check[ny][nx][canvisit]){	
					dis[ny][nx][canvisit] = dis[nowPoint.first][nowPoint.second][canvisit] + 1;
					check[ny][nx][canvisit] = 1;
					qu.push(make_pair(make_pair(ny,nx), canvisit));
				}else if(map[ny][nx] == 1 && !check[ny][nx][1] && canvisit){
					dis[ny][nx][0] = dis[nowPoint.first][nowPoint.second][canvisit] + 1;
					check[ny][nx][0] = 1;
					qu.push(make_pair(make_pair(ny,nx), 0));
				}
			}
		}
	}
}

void resultPrint(){
	if(!dis[N][M][0]  && !dis[N][M][1]){
		printf("-1\n");
		return ;
	}

	if(dis[N][M][0] == 0)
		printf("%d", dis[N][M][1]);
	else if(dis[N][M][1] == 0)
		printf("%d", dis[N][M][0]);
	else if(dis[N][M][1] < dis[N][M][0])
		printf("%d", dis[N][M][1]);
	else 
		printf("%d", dis[N][M][0]);
}