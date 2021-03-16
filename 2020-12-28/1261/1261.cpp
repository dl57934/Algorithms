#include <cstdio>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

#define element pair<int, pair<int, int> >

int xpos[4] = {0, 1, 0, -1};
int ypos[4] = {1, 0, -1, 0};
int visited[102][102], map[102][102], weight[102][102];
priority_queue <element, vector<element>, greater<element> > pq;
int M, N;

void dajickstra();

int main(){
	scanf("%d %d", &M, &N);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf("%1d", &map[y][x]);
			weight[y][x] = INT_MAX;
		}
	}

	dajickstra();

	printf("%d", weight[N][M]);
}

void dajickstra(){
	pq.push(make_pair(0, make_pair(1, 1)));
	weight[1][1] = 0;
	while(!pq.empty()){
		pair<int, int> now = pq.top().second;
		int nowDistance = pq.top().first;
		visited[now.first][now.second] = 1;
		pq.pop();
		for(int i = 0; i < 4; i++){
			int nextY = now.first + ypos[i];
			int nextX = now.second + xpos[i];
			if(nextX <= M && nextX >= 1 && nextY <= N && nextY >=1 && visited[nextY][nextX] == 0){
				if(map[nextY][nextX] == 0){
					if(nowDistance < weight[nextY][nextX]){
						weight[nextY][nextX] = nowDistance;
						pq.push(make_pair(weight[nextY][nextX], make_pair(nextY, nextX)));
					}
				}else{
					if(nowDistance + 1 < weight[nextY][nextX]){
						weight[nextY][nextX] = nowDistance + 1;
						pq.push(make_pair(weight[nextY][nextX], make_pair(nextY, nextX)));
					}
				}
			}
		}
	}
}