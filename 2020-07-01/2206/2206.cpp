#include <cstdio>
#include <queue>

using namespace std;

queue <pair<pair<int, int>, int> > qu;
int map[1002][1002];
int distances[1002][1002][3];
int check[1002][1002][3];
int N, M;
int xpos[4] = {0, 1, 0, -1};
int ypos[4] = {1, 0, -1, 0};

void input();
void bfs();

int main(){
	input();
	bfs();

	if(distances[N][M][0]==0 && distances[N][M][1] ==0 ){
		printf("-1");
		return 0;
	}

	if(distances[N][M][0] == 0){
		printf("%d", distances[N][M][1]);
	}else if(distances[N][M][1] == 0){
		printf("%d", distances[N][M][0]);
	}else if(distances[N][M][1] < distances[N][M][0]){
		printf("%d", distances[N][M][1]);
	}else{
		printf("%d", distances[N][M][0]);
	}
}

void input(){
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf("%1d", &map[y][x]);
		}
	}
} 

// 0이 갈 수 있다. 벽을 부신 전적이 있다.
// 1 갈 수 없다. 벽을 부술 수 있다.
void bfs(){
	qu.push(make_pair(make_pair(1,1), 1));
	distances[1][1][1] = 1;
	distances[1][1][0] = 1;
	check[1][1][1] = 1;
	check[1][1][0] = 1;

	while(!qu.empty()){
		pair<int, int> now = qu.front().first;
		int canBreak = qu.front().second;
		qu.pop();
		for(int pos = 0; pos < 4; pos++){
			int nextY = now.first + ypos[pos];
			int nextX = now.second + xpos[pos];
			if(nextX >= 1 && nextX <= M && nextY >= 1 && nextY <= N){
				if(map[nextY][nextX] == 0 && check[nextY][nextX][canBreak] == 0){
					check[nextY][nextX][canBreak] = 1;
					distances[nextY][nextX][canBreak] = distances[now.first][now.second][canBreak] + 1;
					qu.push(make_pair(make_pair(nextY, nextX), canBreak));
				}else if(map[nextY][nextX] == 1 && check[nextY][nextX][0] == 0 && canBreak == 1){
					check[nextY][nextX][0] = 1;
					distances[nextY][nextX][0] = distances[now.first][now.second][1] + 1;
					qu.push(make_pair(make_pair(nextY, nextX), 0));
				}
			}
		}
	}
}