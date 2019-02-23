#include <cstdio>
#include <queue>

using namespace std;

int xpos[4] = {0, -1, 0, 1};
int ypos[4] = {-1, 0, 1, 0};
int map[51][51]={0, };
int warms = 0;
int M, N, K;
queue <pair<int, int> > qu;	

void link(int from, int to);
void input(int T);
void findCabbage();
int dfs(int x, int y);
void bfs(int x, int y);

int main(){
	int T;
	scanf("%d", &T);
	input(T);
}

void input(int T){
	int x, y;
	for(int i = 0; i < T; i++){
		scanf("%d %d %d",&M, &N, &K);
		for(int j = 0; j < K; j++){
			scanf("%d %d", &x, &y);
			link(x, y);
		}
		findCabbage();
	}
}

void link(int from, int to){
	map[from][to] = 1;
}

void findCabbage(){
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++){
			if(map[i][j] == 1){
				bfs(i, j);
				warms+=1;
			}
		}
		printf("%d\n", warms);
		warms=0;
}

int dfs(int x, int y){
	map[x][y] = 0;
		for(int i = 0; i < 4; i++)
			if(y+ypos[i]<N && x+xpos[i]<M && x+xpos[i]>=-1 && y+ypos[i]>=-1 && map[x+xpos[i]][y+ypos[i]]==1)
				dfs(x+xpos[i], y+ypos[i]);
	return 0;	
}

void bfs(int x, int y){
	qu.push(make_pair(x, y));
	map[x][y] = 0;
	while(!qu.empty()){
		pair <int, int>xy = qu.front();
		qu.pop();
		for(int i = 0; i < 4; i++){
			int ax = xy.first + xpos[i];
            int ay = xy.second + ypos[i];
			if(ax>=0 && ay>=0 && ax<M && ay<N && map[ax][ay] == 1){
				map[ax][ay] = 0;
				qu.push(make_pair(ax, ay));
			}
		}
	}
}

