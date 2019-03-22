#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int map[102][102];
int xpos[4] = {0, 1, 0, -1};
int ypos[4] = {1, 0, -1, 0};
int M, N;
int cheezeSection = 0;
int level = 0;
vector <pair<int, int> > point;
vector <int> cheeze;

void dfs(int x, int y);

int main(){
	
	scanf("%d %d", &M, &N);
	for(int y = 0; y < M; y++)
		for(int x = 0; x < N; x++)
			scanf("%d", &map[y][x]);

	for(int y = 0; y < M; y++){
		map[y][0] = 2;
		map[y][N-1] = 2;
	}		

	for(int x = 0; x < N; x++){
		map[0][x] = 2;
		map[M-1][x] = 2;
	}		

	while(1){
		level +=1;
		for(int y = 0; y < M; y++)
			for(int x = 0; x < N; x++)
				if(map[y][x] == 2)
					dfs(x, y);
		

		for(int y = 0; y < M; y++)
			for(int x = 0; x < N; x++)
				if((map[y+1][x] == 2 || map[y-1][x] == 2 || map[y][x+1] == 2 || map[y][x-1] == 2) && map[y][x] == 1){
					cheezeSection+=1;
					point.push_back(make_pair(y, x));
				}

		if(cheezeSection == 0)
			break;

		for(auto& n : point)
			map[n.first][n.second] = 2;

		cheeze.push_back(cheezeSection);
		
		cheezeSection = 0;
	
	}

	printf("%d\n%d", cheeze.size(), cheeze.back());
	
}

void dfs(int x, int y){
	map[y][x] = 2;
	
	for(int i = 0 ; i < 4; i++){
		int ax = x + xpos[i];
		int ay = y + ypos[i];
		if(ax >=0 && ay >= 0 && ax < N && ay < M && map[ay][ax] == 0){
			
			dfs(ax, ay);
		}
	}
	return ;
}