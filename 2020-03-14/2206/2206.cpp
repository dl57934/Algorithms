#include <cstdio>
#include <utility>
#include <queue>

using namespace std;



queue <pair<pair<int, int>, int> > qu;

int N, M;

int map[1002][1002];
int distanceArray[1002][1002][3];
int checked[1002][1002][3];

int posY[4] = {1, 0, -1, 0};
int posX[4] = {0, 1, 0, -1};

void input();

void bfs();

int main(){
	input();
	bfs();
	for(int y = 1; y <= N; y++){
		for(int x = 1; x<= M; x++){
			printf("%d", distanceArray[y][x][0]);
		}
		printf("\n");
	}
	printf("\n");

	for(int y = 1; y <= N; y++){
		for(int x = 1; x<= M; x++){
			printf("%d", distanceArray[y][x][1]);
		}
		printf("\n");
	}
	
}

void input(){
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x<= M; x++){
			scanf("%1d", &map[y][x]);
		}
	}

	qu.push(make_pair(make_pair(1, 1), 1));
}


void bfs(){
	distanceArray[1][1][0] = 1;
	distanceArray[1][1][1] = 1;

	checked[1][1][0] = 1;
	checked[1][1][1] = 1;

	while(!qu.empty()){
		pair <int, int> point = qu.front().first;
		int canVisit = qu.front().second;
		qu.pop();

		for(int i = 0; i < 4; i++){
			int ay = point.first+posY[i]; 
			int ax = point.second+posX[i];
			if(ay >=1 && ax >=1 && ay <= N && ax <= M){
				if(map[ay][ax] == 0 && checked[ay][ax][canVisit] == 0){
					checked[ay][ax][canVisit] = 1;
					distanceArray[ay][ax][canVisit] = distanceArray[point.first][point.second][canVisit]+1;
					qu.push(make_pair(make_pair(ay,ax), canVisit));
				}else if(map[ay][ax] == 1 && canVisit && checked[ay][ax][0] == 0){
					checked[ay][ax][0] = 1;
					distanceArray[ay][ax][0] = distanceArray[point.first][point.second][canVisit]+1;
					qu.push(make_pair(make_pair(ay,ax), 0));
				}
			
			}	
		}
	}
}