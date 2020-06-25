#include <cstdio>
#include <queue>
using namespace std;

queue <pair<pair<int, int>, int> >qu;
int path[1002][1002][3];
int checked[1002][1002][3];
int map[1002][1002];
int yPos[4] = { 1, -1, 0, 0};
int xPos[4] = { 0, 0, 1, -1};

int N, M;
void input();
void bfs();

int main(){
	input();
	bfs();

	if(path[N][M][0] == 0 && path[N][M][1] == 0){
		printf("-1");
		return 0;
	}

	if(path[N][M][1] == 0 ){
		printf("%d", path[N][M][0]);
	}else if(path[N][M][0] == 0){
		printf("%d", path[N][M][1]);
	}else if(path[N][M][1] < path[N][M][0]){
		printf("%d", path[N][M][1]);
	}else{
		printf("%d", path[N][M][0]);
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

// 1이면 방문한적 있음
//

void bfs(){
	qu.push(make_pair(make_pair(1, 1), 0));

	path[1][1][0] = 1;
	path[1][1][1] = 1;

	checked[1][1][0] = 1;
	checked[1][1][1] = 1;
	while(!qu.empty()){
		pair<int, int> point = qu.front().first;
		int canVisit = qu.front().second;
		qu.pop();
		for(int i = 0; i < 4; i++){
			int nY = point.first + yPos[i];
			int nX = point.second + xPos[i];
			if(nY >= 1 && nY <= N && nX >= 1 && nX <= M){
				if(map[nY][nX] == 0 && checked[nY][nX][canVisit] == 0){
					checked[nY][nX][canVisit] = 1;
					path[nY][nX][canVisit] = path[point.first][point.second][canVisit] + 1;
					qu.push(make_pair(make_pair(nY, nX), canVisit));
				}else if(map[nY][nX]==1 && canVisit == 0 && checked[nY][nX][1] == 0){
					qu.push(make_pair(make_pair(nY, nX), 1));
					checked[nY][nX][1] = 1;
					path[nY][nX][1] = path[point.first][point.second][canVisit] + 1;
				}
			}
		}
	}
}