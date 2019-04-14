#include <stdio.h>
#include <stdlib.h>

int size;
int count = 0;
int map[16];

void nQueen(int map[], int n);
int promise(int map[], int n);


int main(){
	scanf("%d", &size);
	nQueen(map, 0);
	printf("%d", count);
}

void nQueen(int map[], int n){
	if(size == n)
		count+=1;
	for(int i = 0; i < size; i++){
		map[n] = i;
		if(promise(map, n))
			nQueen(map, n+1);
	}
}
int promise(int map[], int n){
	for (int i = 0; i < n; ++i){
		if(map[n] == map[i]) return 0;
		if(abs(n-i) == abs(map[n]-map[i])) return 0;
	}
	return 1;
}