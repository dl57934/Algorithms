#include <cstdio>
#include <queue>

using namespace std;

queue<pair<int, int> > qu;
int N, M;
int map[102][102];
int distances[102][102];
int ypos[4] = {1, -1, 0, 0};
int xpos[4] = {0, 0, 1, -1};

void input();

void bfs();

int main(){
	input();
	bfs();
	printf("%d", distances[N][M]);
}

void input(){
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf("%1d", &map[y][x]);
			if(map[y][x]){
				distances[y][x] = 9876543;
			}
		}
	}
}

void bfs(){
	qu.push(make_pair(1, 1));
	distances[1][1] = 1;
	while(!qu.empty()){
		pair<int, int> now = qu.front();
		qu.pop();
		for(int pos = 0; pos < 4; pos++){
			int nextY = now.first + ypos[pos];
			int nextX = now.second + xpos[pos];
			if(nextX >= 1 && nextX <= M && nextY >= 1 && nextY <= N && map[nextY][nextX] ){
				if(distances[nextY][nextX] > distances[now.first][now.second] + 1){
					distances[nextY][nextX] = distances[now.first][now.second] + 1;
					qu.push(make_pair(nextY, nextX));
				}
			}
		}
	}
}