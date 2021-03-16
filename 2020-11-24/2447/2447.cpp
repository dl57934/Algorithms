#include <cstdio>
#include <vector>
#include <string>

using namespace std;

char board[2188][2188];
int N;
void setBoard(int size, int width, int height, int isMid);

int main(){	
	scanf("%d", &N);
	setBoard(N, 0, 0, 0);

	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			printf("%c", board[y][x]);
		}
		printf("\n");
	}
}

void setBoard(int size, int width, int height, int isMid){
	for(int y = 0; y < size; y++){
		for(int x = 0; x < size; x++){
			if(isMid)
				board[height + y][width + x] = ' ';	
			else
				board[height + y][width + x] = '*';
		}
	}


	if(size >= 3){
		int i = 0;
		for(int y = 0; y < size; y+=size/3){
			for(int x = 0; x < size; x+=size/3){
				i++;
				if(i == 5){
					setBoard(size / 3, width + x, height + y, 1);
				}
				else
					setBoard(size / 3, width + x, height + y, 0);
			}
		}
	}
	
	
}