#include <stdio.h>

int map[102][102]={0,};

int main(){
	int N;
	int x, y;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &x, &y);
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < 10; k++)
				map[x+j][y+k] = 1;
	}

	int result = 0;
	for(int i = 1; i < 101; i++)
		for(int j = 1; j <101; j++)
				result+=map[i][j];
			
		printf("%d", result);
}