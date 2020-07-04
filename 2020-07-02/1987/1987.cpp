#include <cstdio>

int R, C;
void input();
char map[22][22];
int check[30];
int xpos[4] = {0, 1, 0, -1};
int ypos[4] = {1, 0, -1, 0};
void dfs(int y, int x, int count);
int result;

int main(){
	input();
	dfs(0, 0, 1);
	printf("%d", result);
}

void input(){
	scanf("%d %d", &R, &C);

	for(int y = 0; y < R; y++){
		for(int x = 0; x < C; x++){
			scanf(" %c", &map[y][x]);
		}
	}
}

void dfs(int y, int x, int count){
	check[map[y][x] - 'A'] = 1;
	if(count > result)
		result = count;
	for(int pos = 0; pos < 4; pos++){
		int ny = y + ypos[pos];
		int nx = x + xpos[pos];
		if(ny>=0 && ny < R && nx >=0 && nx < C && check[map[ny][nx]-'A'] == 0){
			dfs(ny, nx, count + 1);
		}
	}

	check[map[y][x] - 'A'] = 0;
}