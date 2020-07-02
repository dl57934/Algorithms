#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int maxSize = 0, minSize = 9876543;
int safeSection;
int map[102][102];
int limitMap[102][102];
int ypos[4] = {0, 1, 0, -1};
int xpos[4] = {1, 0, -1, 0};
vector<int> result;
void input();
void setlimit();
void dfs(int y, int x);

int main(){
	input();
	setlimit();
	
	printf("%d", *max_element(result.begin(), result.end()));
}

void input(){
	scanf("%d", &N);
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			scanf("%d", &map[y][x]);
			if(map[y][x] > maxSize)
				maxSize = map[y][x];
			if(map[y][x] < minSize)
				minSize = map[y][x];
		}
	}
}

void setlimit(){
	for(int size = 0; size <= maxSize; size++){
		for(int y = 1; y <= N; y++)
			for(int x = 1; x <= N; x++)
				if(map[y][x] > size)
					limitMap[y][x] = 1;

		for(int y = 1; y <= N; y++){
			for(int x = 1; x <= N; x++){
				if(limitMap[y][x] == 1){
					safeSection++;
					dfs(y, x);
				}	
			}
		}
		
		result.push_back(safeSection);
		safeSection=0;	
		
	}
}

void dfs(int y, int x){
	limitMap[y][x] = 0;

	for(int pos = 0; pos < 4; pos++){
		int nextY = y + ypos[pos];
		int nextX = x + xpos[pos];

		if(nextY >= 1 && nextY <=N && nextX>=1 && nextX<=N && limitMap[nextY][nextX] == 1){
			dfs(nextY, nextX);
		}
	}
}