#include <cstdio>

int originMap[102][102];
int diseaseMap[102][102];

int N;
int xpos[4] = {1, 0, -1, 0};
int ypos[4] = {0, 1, 0, -1};
void input();
void findsection();
void dfs(int map[102][102], int y, int x);

int main(){
	input();
	findsection();
}

void input(){ // R1 G2 B3
	
	char color;
	scanf("%d", &N);
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			scanf(" %c", &color);
			if(color == 'B'){
				originMap[y][x] = 3;
				diseaseMap[y][x] = 3;
			}else if(color == 'G' || color == 'R'){
				if(color == 'G')
					originMap[y][x] = 2;
				if(color == 'R')
					originMap[y][x] = 1;
				diseaseMap[y][x] = 1;
			}
		}
	}
}

void findsection(){
	int count1 = 0, count2 = 0;
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			if(originMap[y][x] != 0){
				count1++;
				dfs(originMap, y, x);
			}
			if(diseaseMap[y][x] != 0){
				count2++;
				dfs(diseaseMap, y, x);
			}
		}
	}

	printf("%d %d", count1, count2);
}

void dfs(int map[102][102], int y, int x){
	int value = map[y][x];
	map[y][x] = 0;
	for(int pos = 0; pos < 4; pos++){
		int nextY = y + ypos[pos];
		int nextX = x + xpos[pos];
		if(nextY >=1 && nextY <= N && nextX >= 1 && nextX <= N && value == map[nextY][nextX] && map[nextY][nextX] != 0){
			dfs(map, nextY, nextX);
		}
	}
}



