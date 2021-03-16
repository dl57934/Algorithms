#include <cstdio>

int N, M;
int map[102][102], copyMap[102][102], visit[102][102];
int ypos[4] = {0, 1, 0, -1}, xpos[4] = {1, 0, -1, 0};
void innerCheeze(int y, int x);
void removeCheeze(int y, int x);
void init();

int main(){
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf("%1d", &map[y][x]);
		}
	}

	for(int time = 1; 1; time++){
		init();
		innerCheeze(1, 1);
		int flag = 0;

		for(int y = 1; y <= N; y++){
			for(int x = 1; x <= M; x++){
				if(map[y][x] == 1){
					flag = 1;
					removeCheeze(y, x);
				}
			}
		}
		if(flag == 0){
			printf("%d", time-1);
			break;
		}
	}
}

void removeCheeze(int y, int x){
	visit[y][x] = 1;
	int count = 0;
	
	for(int i = 0; i < 4; i++){
		int newY = y + ypos[i];
		int newX = x + xpos[i];

		if(copyMap[newY][newX] == 2 && newY >=1 && newY <= N && newX >= 1 && newX <= M){
			count++;
			if(count == 2){
				map[y][x] = 0;
				break;
			}
		}

		if(copyMap[newY][newX] == 1 && newY >=1 && newY <= N && newX >= 1 && newX <= M && visit[newY][newX] == 0){
			removeCheeze(newY, newX);
		}
	}	
}

void innerCheeze(int y, int x){
	copyMap[y][x] = 2;
	for(int i = 0; i < 4; i++){
		int newY = y + ypos[i];
		int newX = x + xpos[i];
		if(newY >=1 && newY <= N && newX >= 1 && newX <= M && copyMap[newY][newX] == 0){
			innerCheeze(newY, newX);
		}
	}
}

void init(){
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			if(map[y][x] == 2)
				map[y][x] = 0;
			visit[y][x] = 0;
			copyMap[y][x] = map[y][x];
		}
	}
}