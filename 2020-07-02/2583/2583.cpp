#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct point{
	int x, y;
}point;

int M, N, K;
int ypos[4] = {1, 0, -1, 0};
int xpos[4] = {0, 1, 0, -1};
int map[102][102];
int section;
vector<int> result;
void input();
void dfs(int y, int x);

int main(){
	input();
	sort(result.begin(), result.end());
	printf("%d\n", result.size());

	for(auto element: result){
		printf("%d ", element);
	}
}

void input(){
	
	point leftSide, rightSide;
	scanf("%d %d %d", &M, &N, &K);
	for(int square = 0; square < K; square++){
		scanf("%d %d %d %d", &leftSide.x, &leftSide.y, &rightSide.x, &rightSide.y);

		for(int y = leftSide.y; y < rightSide.y; y++){
			for(int x = leftSide.x; x < rightSide.x; x++){
				map[y][x] = 1;
			}
		}
	}

	for(int y = 0; y < M; y++)
		for(int x = 0; x < N; x++)
			if(map[y][x] == 0){
				dfs(y, x);
				result.push_back(section);
				section=0;
			}
	
}

void dfs(int y, int x){
	section+=1;
	map[y][x] = 1;

	for(int pos = 0; pos < 4; pos++){
		int nextY = y + ypos[pos];
		int nextX = x + xpos[pos];
		if(nextY >= 0 && nextY < M && nextX >= 0 && nextX < N && map[nextY][nextX] == 0){
			dfs(nextY, nextX);
		}
	}
}

