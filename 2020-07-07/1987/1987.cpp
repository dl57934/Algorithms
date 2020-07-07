#include <cstdio>

int R, C;
int maxNum=0;
int map[22][22];
int check[26];
int ypos[4] = {1, -1, 0, 0};
int xpos[4] = {0, 0, 1, -1};
void input();
void dfs(int y, int x, int limit);

int main(){
	input();
	check[map[0][0]] = 1;
	dfs(0, 0, 1);
	printf("%d", maxNum);
}

void input(){
	char letter;
	scanf("%d %d", &R, &C);
	for(int y = 0; y < R; y++){
		for(int x = 0; x < C; x++){
			scanf(" %c", &letter);
			map[y][x] = letter -'A';
		}
	}
}



void dfs(int y, int x, int limit){
	if(maxNum < limit)
		maxNum=limit;
	for(int pos = 0; pos < 4; pos++){
		int newY = ypos[pos] + y;
		int newX = xpos[pos] + x;
		if(newX >= 0 && newY>=0 && newX < C && newY < R && check[map[newY][newX]] == 0){
			check[map[newY][newX]] = 1;
			dfs(newY, newX, limit+1);
			check[map[newY][newX]] = 0;
		}
	}
}