#include <stdio.h>
#include <string.h>

int RGB[4][1003] = {0, };
int result[4][1003] = {0, };
int N;

void setRGB(int color, int floor);
void getMin(int floor);
void initRGB();

int main(){
	int R, G, B;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d %d", &RGB[1][i], &RGB[2][i], &RGB[3][i]);
	memcpy(result, RGB, sizeof(RGB));
	for(int i = 1; i <= 3; i++){
		setRGB(i, 0);
		getMin(N-1);
		initRGB();
	}
}

void setRGB(int color, int floor){
	
}
void initRGB(){
	memcpy(RGB, result, sizeof(result));
}

void getMin(int floor){
	printf("%d %d %d\n", RGB[1][floor], RGB[2][floor], RGB[3][floor]);
}