#include <cstdio>

int R, C;
int xpos[4] = {1, 0, -1, 0};
int ypos[4] = {0, 1, 0, -1};
int map[22][22];
int check[27];
int maxCount;

void dfs(int y, int x, int count);

int main(){
	
	char num;

	scanf("%d %d", &R, &C);

	for(int y = 0; y < R; y++){
		for(int x = 0; x < C; x++){
			scanf(" %1c", &num);
			map[y][x] = num - 'A';
		}
	}
	dfs(0, 0, 1);

	printf("%d", maxCount);
}

void dfs(int y, int x, int count){
	check[map[y][x]] = 1;
	if(maxCount < count)
		maxCount = count;

	for(int i = 0; i < 4; i++){
		int nY = y + ypos[i];
		int nX = x + xpos[i];
		if(nY>=0 && nX>=0 && nY<R && nX<C && check[map[nY][nX]] == 0){
			dfs(nY, nX, count+1);
			check[map[nY][nX]] = 0;
		}
	}
}