#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

queue <pair<int, int> > qu;

int N;
int map[27][27];

int xpos[4] = {1, 0, -1, 0};
int ypos[4] = {0, 1, 0, -1};

int houseIndex = 0;
int house[500];
int houseComplex = 0;

void input();
void calculator();
void dfs(int x, int y);
void bfs(int x, int y);

int main(){
	input();
	calculator();
	sort(house, house+houseIndex);
	printf("%d\n", houseComplex);
	for(int i = 0; i < houseIndex; i++)
		printf("%d\n", house[i]);
}

void input(){
	scanf("%d", &N);
	 fflush(stdin);
	for(int i = 0; i < N;i++){
		for(int j = 0; j < N; j++){
			scanf("%1d", &map[i][j]);
		}
	} 
}

void dfs(int x, int y){
	map[y][x] = 0;
	house[houseIndex]++;
	for(int i = 0; i < 4; i++){
		if(map[y+ypos[i]][x+xpos[i]] && y+ypos[i] >= 0 && x+xpos[i] >= 0)
			dfs(x+xpos[i], y+ypos[i]);
	}
}

void bfs(int x, int y){
	map[y][x] = 0;
	while(!qu.empty()){
		pair<int, int> point = qu.front();
		qu.pop();
		house[houseIndex]++;
		
		for(int i = 0; i < 4; i++){
			int ax = xpos[i]+point.second;
			int ay = ypos[i]+point.first;
			if(map[ay][ax] && ay>=0 && ax>=0){
				map[ay][ax] = 0;
				qu.push(make_pair(ay, ax));
			}
		}
	}
}


void calculator(){
	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			if(map[y][x]){
				houseComplex++;
				qu.push(make_pair(y, x));
				bfs(x, y);
				houseIndex++;
			}
		}
	}
}