#include <stdio.h>

char map[3072][6144];
void stars(int n, int x, int y);

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= 2*N-1; j++){
			if(j == 2*N-1)
				map[i][j] ='\0';
			else 
				map[i][j] = ' ';
		}
	}
	stars(N, N-1, 0);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < 2*N-1; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void stars(int n, int x, int y){
	if(n == 3){
		map[y][x] = '*';
		map[y+1][x-1] = '*';
		map[y+1][x+1] = '*';
		map[y+2][x-2] = '*';
		map[y+2][x-1] = '*';
		map[y+2][x] = '*';
		map[y+2][x+1] = '*';
		map[y+2][x+2] = '*';
		return ;
	}else{
		stars(n/2, x, y);
		stars(n/2, x-(n/2), y+(n/2));
		stars(n/2, x+(n/2), y+(n/2));
	}
}