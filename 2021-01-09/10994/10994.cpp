#include <cstdio>

char map[400][400];
int size;
void setBoard(int y, int x, int block, int direction);

int main(){
	int N;
	scanf("%d", &N);

	size = 4 * N - 3;

	int midX = size/2, midY = size/2;

	setBoard(midY, midX, 1, 0);

	for(int y = 0; y < size; y++){
		for(int x = 0; x < size; x++){
			if(map[y][x])
				printf("%c", map[y][x]);
			else
				printf(" ");
		}
		printf("\n");
	}
}



void setBoard(int y, int x, int block, int direction){
	if(y == x){
		map[y][x] = '*';
	}else{
		int size = block/2;
		if(direction == 1){
			for(int start = x - size; start <= x + size; start++){
				map[y][start] = '*';
			}
		}else if(direction == 2){
			for(int start = x - size; start <= x + size; start++){
				map[y][start] = '*';
			}
		}else if(direction == 3){
			for(int start = y - size; start <= y + size; start++){
				map[start][x] = '*';
			}
		}else{
			for(int start = y - size; start <= y + size; start++){
				map[start][x] = '*';
			}
		}
	}

	if(y > 0 && x > 0 && y < size - 1 && x < size - 1){
		if(y - 2 >= 0 && !map[y-2][x]){
			setBoard(y-2, x, block + 4, 1);
		}
	

		if(y + 2 <= size -1 && !map[y+2][x]){
			setBoard(y+2, x, block + 4, 2);
		}
	

		if(x - 2 >= 0 && !map[y][x-2]){
			setBoard(y, x-2, block + 4, 3);
		}
	

		if(x + 2 <= size-1 && !map[y][x+2]){
			setBoard(y, x+2, block + 4, 4);
		}
	}
}