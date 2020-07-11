#include <cstdio>
int count = 0;
int N, M;
int map[53][53], destination[53][53];

void input();
void swap(int y, int x);
int isSameMap();

int main(){
	input();

	if(isSameMap()){
		printf("%d", count);
		return 0;
	}

	for(int y = 0; y < N-2; y++){
		for(int x = 0; x < M-2; x++){
			if(map[y][x] != destination[y][x]){
				count++;
				swap(y, x);
				if(isSameMap()){
					printf("%d", count);
					return 0;
				}
			}
		}
	}

	printf("-1");
}

void input(){
	scanf("%d %d", &N, &M);
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			scanf("%1d", &map[y][x]);
		}
	}

	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			scanf("%1d", &destination[y][x]);
		}
	}
}

void swap(int y, int x){
	for(int ypos = y; ypos < y+3; ypos++){
		for(int xpos = x; xpos < x+3; xpos++){
			map[ypos][xpos] = (map[ypos][xpos] == 1? 0 : 1);
		}
	}
}

int isSameMap(){
	for(int y = 0; y < N; y++)
		for(int x = 0; x < M; x++)
			if(map[y][x] != destination[y][x])
				return 0;

	return 1;
}