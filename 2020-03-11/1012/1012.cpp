#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

queue <pair<int, int> > qu;

int M, N;
int T;
int swarm = 0;
int allSwarm = 0;
int map[52][52];

int xPoint[5] = { 1, 0 , -1, 0};
int yPoint[5] = { 0, 1 , 0, -1};

void input();
void findSwarm();
void dfs(int y, int x);
void bfs(int y, int x);


int main(){
	input();
}

void input(){
	scanf("%d", &T);
	for(int caseNum = 0; caseNum < T; caseNum++){
		scanf("%d %d %d", &M, &N, &swarm);
		for(int i = 0; i < swarm; i++){
			int y, x;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		findSwarm();
		printf("%d\n", allSwarm);
		allSwarm = 0;
	}
}

void findSwarm(){
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			if(map[y][x]){
				allSwarm+=1;
				qu.push(make_pair(y, x));
				bfs(y, x);
			}
		}
	}
}

void dfs(int y, int x){
		map[y][x] = 0;
	for(int i = 0; i < 4; i++){
		if(map[y+yPoint[i]][x+xPoint[i]] && x+xPoint[i] >= 0 && y+yPoint[i] >= 0){
			dfs(y+yPoint[i], x+xPoint[i]);
		}
	}
}

void bfs(int y, int x){
	map[y][x] = 0;
	while(!qu.empty()){
		pair<int, int> point = qu.front();
		qu.pop();
		for(int i = 0; i < 4; i++){
			int ay = point.first+ yPoint[i];
			int ax = point.second+ xPoint[i];
			if(map[ay][ax] && ay >= 0 && ax>=0){
				map[ay][ax] = 0;
				qu.push(make_pair(ay, ax));
			}
		}
	}
}