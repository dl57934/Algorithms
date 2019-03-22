#include <cstdio>

char map[3072][6143];
int N;

void initMap();
void printMap();
void stars(int n, int x, int y);
void markStars(int x, int y);

int main(){
	scanf("%d", &N);
	initMap();
	stars(N, N-1, 0);
	printMap();
}

void initMap(){
	for(int y = 0; y < N; y++)
		for(int x = 0; x < 2*N-1; x++)
			map[y][x] = ' ';
}

void stars(int n, int x, int y){
	if(n == 3){
		markStars(x, y);
		return ;
	}else{
		stars(n/2, x, y);
		stars(n/2, x-(n/2),y+(n/2));
		stars(n/2, x+(n/2),y+(n/2));
	}
	
}

void markStars(int x, int y){
	map[y][x] = '*';
	map[y+1][x-1] = '*';
	map[y+1][x+1] = '*';
	map[y+2][x-2] = '*'; 
	map[y+2][x-1] = '*';
	map[y+2][x] = '*';
	map[y+2][x+1] = '*';
	map[y+2][x+2] = '*';	
}


void printMap(){
	for(int y = 0; y < N; y++){
		for(int x = 0; x < 2*N-1; x++){
			printf("%c", map[y][x]);
		}
		printf("\n");
	}
}