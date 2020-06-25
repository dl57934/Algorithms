#include <cstdio>
#include <queue>

using namespace std;

int ypos[4] = {1, -1, 0, 0};
int xpos[4] = {0, 0, -1, 1};
int N, M;
int map[102][102];
queue<pair<int, int> > qu;

void input();
void bfs();
int main(){
	input();
	bfs();
	printf("%d", map[N-1][M-1]);
}

void input(){
	scanf("%d %d", &N, &M);

	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			scanf("%1d", &map[y][x]);
		}
	}
	qu.push(make_pair(0, 0));
}

void bfs(){
	while(!qu.empty()){
		pair<int, int> point = qu.front();
		qu.pop();
		for(int i = 0; i < 4; i++){
			int nextY = point.first + ypos[i];
			int nextX = point.second + xpos[i];
			if(nextY >= 0 && nextX >= 0){
				if(map[nextY][nextX] > map[point.first][point.second] + 1 || map[nextY][nextX] == 1){
					qu.push(make_pair(nextY, nextX));
					map[nextY][nextX] = map[point.first][point.second] + 1;
				}
			}
		}
	}
}