#include <cstdio>

int N, M;
void input(int map[52][52]);
int isSame(int origin[52][52], int trans[52][52]);
void change(int map[52][52], int y, int x);

int main(){
	int count = 0;
	int start[52][52] = {0, }, destination[52][52] = {0, };
	scanf("%d %d", &N, &M);
	
	input(start);
	input(destination);
	if(N < 3 || M < 3){
		if(isSame(start, destination))	
			printf("%d", count);
		else
			printf("-1");
		return 0;
	}
	
	
	for(int y = 0; y < N-2; y++){
		for(int x = 0; x < M-2; x++){
			if(start[y][x] != destination[y][x]){
				count++;
				change(start, y, x);
				if(isSame(start, destination)){
					printf("%d", count);
					return 0;
				}
			}
		}
	}

	printf("-1");
}

void input(int map[52][52]){
	for(int y = 0; y < N; y++)
		for(int x = 0; x < M; x++)
			scanf("%1d", &map[y][x]);	
}

void change(int map[52][52], int y, int x){
	for(int ypos = y; ypos < y+3; ypos++)
		for(int xpos = x; xpos < x+3; xpos++)
			map[ypos][xpos] = map[ypos][xpos] == 0 ? 1:0;
}

int isSame(int origin[52][52], int trans[52][52]){
	for(int y = 0; y < N; y++)
		for(int x = 0; x < M; x++)
			if(origin[y][x] != trans[y][x])
				return 0;
	return 1;
}