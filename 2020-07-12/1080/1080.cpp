#include <cstdio>

int N, M;
int originMap[52][52];
int resultMap[52][52];
int check();
void input();
void change(int y, int x);

int main(){
	int count = 0;
	input();

	
	if(check()){
		printf("0");
		return 0;
	}
	else {
		if(N < 3 || M < 3){
			printf("-1");
			return 0;
		}
	}

	for(int y = 0; y < N-2; y++){
		for(int x = 0; x < M-2; x++){
			if(originMap[y][x] != resultMap[y][x]){
				count++;
				change(y, x);
				if(check()){
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
			scanf("%1d", &originMap[y][x]);

	for(int y = 0; y < N; y++)
		for(int x = 0; x < M; x++)
			scanf("%1d", &resultMap[y][x]);
}	

void change(int y, int x){
	for(int ypos = y; ypos < y+3; ypos++){
		for(int xpos = x; xpos < x+3; xpos++){
			originMap[ypos][xpos] = originMap[ypos][xpos] == 1? 0 : 1;
		}
	}
}

int check(){
	for(int ypos = 0; ypos < N; ypos++){
		for(int xpos = 0; xpos < M; xpos++){
			if(originMap[ypos][xpos] != resultMap[ypos][xpos])
				return 0;
		}
	}	
	return 1;
}