#include <cstdio>
#include <queue>

using namespace std;
int ypos[4] = {0, 1, 0, -1}, xpos[4] = {1, 0, -1, 0};
int map[102][102], weight[102][102];

void bfs();

int N, M;

int main(){
	
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf("%1d", &map[y][x]);
		}
	}

	bfs();
}

void bfs(){
	queue<pair<int, int> > qu;
	qu.push(make_pair(1, 1));

	while(!qu.empty()) {
		pair<int, int> now = qu.front();
		qu.pop();

		for(int i = 0; i < 4; i++){
			int nextY = now.first + ypos[i];
			int nextX = now.second + xpos[i];
			if(map[nextY][nextX] && (weight[nextY][nextX] == 0 || weight[nextY][nextX] > weight[now.first][now.second] + 1)){
				weight[nextY][nextX] = weight[now.first][now.second] + 1;
				qu.push(make_pair(nextY, nextX));
			}
		}
	}

	printf("%d", weight[N][M] + 1);
}