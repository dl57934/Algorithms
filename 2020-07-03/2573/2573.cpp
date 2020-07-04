#include <cstdio>

int N, M;
int copyMap[1000][1000];
int originMap[1000][1000];
int ypos[4] = {1, -1, 0, 0};
int xpos[4] = {0, 0, 1, -1};

void copy();
void input();
void dfs(int y, int x);
void deserve();
void spendYear();
void input();

int main(){
	input();
	spendYear();
}

void input(){
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf("%d", &originMap[y][x]);
		}
	}
}

void copy(){
	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= M; x++)
			copyMap[y][x] = originMap[y][x];
}

void spendYear(){
	int year = 1;
	while(1){
		copy();
		deserve();
		copy();
		int section = 0;
		for(int y = 1; y <= N; y++){
			for(int x = 1; x <= M; x++){
				if(copyMap[y][x]){
					section++;
					dfs(y,x);
				}
			}
		}

		if(section > 1){
			printf("%d", year);
			return ;
		}else if(section == 0){
			printf("0");
			return ;
		}
		year++;
	}
}

void deserve(){
	for(int y = 1; y <= N; y++){
			for(int x = 1; x <= M; x++){
				if(copyMap[y][x]){
					for(int pos = 0; pos < 4; pos++){
						int newY = ypos[pos] + y;
						int newX = xpos[pos] + x;
						if(newY >= 1 && newY <= N && newX >= 1 && newX <= M && !copyMap[newY][newX]){
							originMap[y][x]-=1;
							if(originMap[y][x] < 1)
								originMap[y][x] = 0;
						}
					}
				}
			}
		}
}

void dfs(int y, int x){
	copyMap[y][x] = 0;
	for(int pos = 0; pos < 4; pos++){
		int newY = ypos[pos] + y;
		int newX = xpos[pos] + x;
		if(newY >= 1 && newY <= N && newX >= 1 && newX <= M && copyMap[newY][newX]){
			dfs(newY, newX);
		}
	}
}