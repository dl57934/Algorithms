#include <stdio.h>

char map[3072][6144];

void arrayInit(int N);
void stars(int n, int x, int y);
void printStars(int N);

int main(){
	int N;
	scanf("%d", &N);
	arrayInit(N);
	stars(N, N-1, 0);
	printStars(N);
}

void arrayInit(int N){
	int lastLine = 2*N-1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= lastLine; j++){
			if(j == lastLine)
				map[i][j] = '\0';
			else
				map[i][j] = ' ';
		}
	}	
}


void stars(int n, int x, int y){
	if(n == 3){
		map[y][x] = '*';
		map[y+1][x-1]= '*';
		map[y+1][x+1]= '*';
		map[y+2][x-2] = '*'; 
		map[y+2][x-1] = '*';
		map[y+2][x] = '*';
		map[y+2][x+2] = '*'; 
		map[y+2][x+1] = '*';
		return;
	}else{
		stars(n/2, x, y);
		stars(n/2, x-(n/2), y+(n/2));
		stars(n/2, x+(n/2), y+(n/2));
	}
}

void printStars(int N){
	int lastLine = 2*N-1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < lastLine; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}	
}