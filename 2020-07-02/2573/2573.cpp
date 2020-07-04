#include <cstdio>

int N, M;
int map[303][303];
int copyMap[303][303];
int ypos[4] = {0, -1, 0, 1};
int xpos[4] = {1, 0, -1, 0};

void input();
void copy();
void spendYear();
void dfs(int y, int x);

int main(){
	input();
	spendYear();
}

void input(){
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= M; x++)
			scanf("%d", &map[y][x]);
}

void copy(){
	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= M; x++)
			copyMap[y][x] = map[y][x];
}

void spendYear(){
	copy();
	int num = 0;
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			if(copyMap[y][x] != 0){
				num++;
				dfs(y, x);
			}
		}
	}

	if(num > 1){
		printf("0");
		return;
	}
	int year = 1;
	while(1){
		copy();
		for(int y = 1; y <= N; y++){
			for(int x = 1; x <= M; x++){
				if(copyMap[y][x] != 0){
					for(int pos = 0; pos < 4; pos++){
						int newY = y + ypos[pos];
						int newX = x + xpos[pos];
						if(newY >= 1 && newX >= 1 && newY <= N && newX <= M && copyMap[newY][newX] == 0){
							map[y][x]-=1;
							if(map[y][x] < 0)
								map[y][x] = 0;
						}
					}
				}
			}
		}
		int count = 0;
		copy();
		for(int y = 1; y <= N; y++){
			for(int x = 1; x <= M; x++){
				if(copyMap[y][x]){
					count++;
					dfs(y,x);
				}	
			}
		}
		if(count > 1){
			printf("%d", year);
			return;
		}else if(count == 0){
			printf("0");
			break;
		}
		year++;
		
	}
	
}

void dfs(int y, int x){
	copyMap[y][x] = 0;

	for(int pos = 0; pos < 4; pos++){
		int newY = y + ypos[pos];
		int newX = x + xpos[pos];
		if(newY >= 1 && newX >= 1 && newY <= N && newX <= M && copyMap[newY][newX]){
			dfs(newY, newX);
		}
	}
}