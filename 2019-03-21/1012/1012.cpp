#include <cstdio>

int map[53][53];
int xpos[4] = {-1, 0, 1, 0};
int ypos[4] = {0, -1, 0, 1};

int M, N, K;
int worms = 0;
void dfs(int x, int y);

int main(){
	int T; 
	int x, y;
	scanf("%d", &T);
	for(int i = 0 ; i<T; i++){
		scanf("%d %d %d", &M, &N, &K);

		for(int pos = 0;  pos < K; pos++){
			scanf("%d %d", &y, &x);
			map[x][y] = 1;
		}

	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			if(map[y][x] == 1){
				dfs(x, y);
				worms +=1;
			}
		}
	}
	printf("%d\n", worms);
	worms = 0;
}


	
	
}

void dfs(int x, int y){
	map[y][x] = 0;

	for(int i = 0; i < 4; i++){
		int newX = xpos[i] + x;
		int newY = ypos[i] +y;
		if( newX < M  && newX >=0 && newY >=0 && newY < N && map[newY][newX] == 1){
			dfs(newX, newY);
		}
	}
	return ;
}