#include <stdio.h>
#include <stdlib.h>

int N;
int method=0;
int isOverlap(int layer);
void nQueens(int layer);

int main(){
	scanf("%d", &N);
	nQueens(0);
}

void nQueens(int layer){
	if(layer == N){
		method+=1;
		return;
	}
	for(int i = 0; i < layer; i++){
		arr[layer] = i;
		nQueens(layer+1);
	}

}

int isOverlap(int layer){
	for(int i = 0; i < layer; i++){
		if(arr[layer] == arr[i]) return 0;
		if(abs(layer - i) == abs(arr[layer] - arr[i])) return 0;
	}
	return 1;
}