#include <cstdio>
#include <queue>

using namespace std;
int xpos[4] = {0, 1, 0, -1}, ypos[4] = {1, 0, -1, 0};
void init();
queue<pair<pair<int, int>, int> > qu;
int map[52][52], weight[52][52], visited[52][52];
int N;
void bfs();

int main(){
	
	scanf("%d", &N);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			scanf("%1d", &map[y][x]);
		}
	}

	init();
	bfs();
	printf("%d", weight[N][N]);
}

void init(){
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			weight[y][x] = 987654321;
		}
	}
	weight[1][1] = 0;
}

void bfs(){
	qu.push(make_pair(make_pair(1, 1), 0));

	while(!qu.empty()){
		pair<int, int> now = qu.front().first;
		int nowY = now.first, nowX = now.second;
		int cost = qu.front().second;
		qu.pop();
		for(int i = 0; i < 4; i++){
			int nextY = nowY + ypos[i];
			int nextX = nowX + xpos[i];

			if(nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= N){
				if(map[nextY][nextX] == 0){
					if(weight[nextY][nextX] > cost + 1){
						weight[nextY][nextX] = cost + 1;
						qu.push(make_pair(make_pair(nextY, nextX), cost+1));
					}
				}else{
					if(weight[nextY][nextX] > cost){
						weight[nextY][nextX] = cost;	
						qu.push(make_pair(make_pair(nextY, nextX), cost));
					}
				}
			}
		}
	}
}