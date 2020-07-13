#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int map[102][102];
int ypos[4] = {0, 1, 0, -1};
int xpos[4] = {1, 0, -1, 0};

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
}

void bfs(){
	queue <pair<int, int> > qu;
	qu.push(make_pair(0, 0));

	while(!qu.empty()){
		pair<int, int> now = qu.front();
		int nowY = now.first;
		int nowX = now.second;
		qu.pop();

		for(int i = 0; i < 4; i++){
			int nextY = nowY + ypos[i];
			int nextX = nowX + xpos[i];
			if(nextY >= 0 && nextX >= 0 && nextY <= N && nextX <= M && map[nextY][nextX]){
				if(map[nextY][nextX] == 1 || map[nextY][nextX] > map[nowY][nowX] + 1){
					map[nextY][nextX] = map[nowY][nowX] + 1;
					qu.push(make_pair(nextY, nextX));
				}
			}
		}
	}
}