#include <cstdio>

int N, M;
int origin[52][52], result[52][52];
void input();
void change(int y, int x);
int checkSame();

int main(){
	input();
	int count = 0;

	if(N < 3 || M < 3){
		if(checkSame()){
			printf("%d", count);
			return 0;
		}else{
			printf("-1");
			return 0;
		}
	}

	for(int y = 0; y < N-2; y++){
		for(int x = 0; x < M-2; x++){
			if(origin[y][x] != result[y][x]){
				count ++;
				change(y, x);
				if(checkSame()){
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
	for(int y = 0; y < N; y++)
		for(int x = 0; x < M; x++)
			scanf("%1d", &origin[y][x]);
		
	for(int y = 0; y < N; y++)
		for(int x = 0; x < M; x++)
			scanf("%1d", &result[y][x]);
}

void change(int y, int x){
	for(int ypos = y; ypos < y+3; ypos++)
		for(int xpos = x; xpos < x+3; xpos++)
			origin[ypos][xpos] = origin[ypos][xpos] == 1? 0 : 1;
}

int checkSame(){
	for(int y = 0; y < N; y++)
		for(int x = 0; x < M; x++)
			if(origin[y][x] != result[y][x])
				return 0;
	return 1;
}