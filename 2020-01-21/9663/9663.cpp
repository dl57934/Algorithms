#include <stdio.h>
#include <stdlib.h>

int chess[20] = {0, };
int N;
int isRightChess(int layer);
int method = 0;
void getMehtod(int layer);

int main(){
	scanf("%d", &N);
	getMehtod(0);
	printf("%d", method);
}

void getMehtod(int layer){
	if(layer == N){
		method+=1;
		return;
	}

	for(int i = 0; i < N; i++){
		chess[layer] = i;
		if(isRightChess(layer))
			getMehtod(layer+1);
	}
}

int isRightChess(int layer){
	for(int i = 0; i < layer; i++){
		if(chess[layer] == chess[i]) return 0;
		if(abs(layer-i) == abs(chess[layer]-chess[i])) return 0;
	}

	return 1;
}