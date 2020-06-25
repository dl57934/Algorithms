#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int home[2500];
int map[26][26];
int ypos[4] = {1, -1, 0, 0};
int xpos[4] = {0, 0, 1, -1};
int N;
int complextTown = 0;
void input();
void dfs(int y, int x);

int main(){
	input();
}

void input(){
	
	scanf("%d", &N);

	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			scanf("%1d", &map[y][x]);
		}
	}

	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			if(map[y][x] == 1){
				dfs(y, x);
				complextTown+=1;
			}
		}
	}
	sort(home, home + complextTown);
	printf("%d\n", complextTown);
	for(int i = 0; i < complextTown; i++){
		printf("%d\n", home[i]);
	}
}

void dfs(int y, int x){
	map[y][x] = 0;
	home[complextTown]+=1;
	for(int i = 0; i < 4; i++){
		int nextY = y + ypos[i];
		int nextX = x + xpos[i];
		if(map[nextY][nextX] == 1 && nextY < N && nextX < N && nextY >= 0 && nextX >= 0){
			dfs(nextY, nextX);
		}
	}
}