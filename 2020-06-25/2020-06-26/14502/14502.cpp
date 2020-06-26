#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void copy();
int N, M;
vector<int> check(66, 0);
vector<pair<int, int> > walls;
vector<pair<int, int> > selectWall(3, make_pair(0, 0));
int ypos[4] = {1, -1, 0, 0 };
int xpos[4] = {0, 0, 1, -1};
vector<int>  mapCheck[10];
int map[10][10];
int copyMap[10][10];
int sum = 0;
vector<int> safeSection;

void dfs(int yPoint, int xPoint);
void back(int limit);
void input();

int main(){
	input();
	back(0);
	printf("%d", *max_element(safeSection.begin(), safeSection.end()));
}

void back(int limit){
	if(limit == 3){
		copy();
		for(int i = 0; i < 3; i++)
			copyMap[selectWall[i].first][selectWall[i].second] = 1;
		for(int i = 0; i < 8; i++)
			mapCheck[i].clear();

		for(int y = 0; y < N; y++){
			for(int x = 0; x < M; x++){
				if(copyMap[y][x] == 2){
					dfs(y, x);
				}
			}
		}
		int safe = 0;
		for(int y = 0; y < N; y++)
			for(int x = 0; x < M; x++){
				if(copyMap[y][x] == 0)
					safe+=1;
			}
		safeSection.push_back(safe);
		return ;
	}	

	for(int i = 0; i < walls.size(); i++){
		if(!check[i]){
			check[i] = 1;
			selectWall[limit] = walls[i];
			back(limit+1);
			check[i] = 0;
		}
	}
}

void input(){
	int value; // 0 soso, 1 wall, 2 germ
	scanf("%d %d", &N, &M);
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			scanf("%d", &map[y][x]);
			if(map[y][x] == 0){
				walls.push_back(make_pair(y, x));
			}
		}
	}
}

void copy(){
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			copyMap[y][x] = map[y][x];
		}
	}
}

void dfs(int yPoint, int xPoint){
	copyMap[yPoint][xPoint] = 3;

	for(int i = 0; i < 4; i++){
		int ny = yPoint + ypos[i];
		int nx = xPoint + xpos[i];
		if(ny >= 0 && ny < N && nx >= 0 && nx < M && copyMap[ny][nx] == 0){
			dfs(ny, nx);
		}
	}
}