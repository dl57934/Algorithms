#include <cstdio>
#include <stdlib.h>
int N;
int count = 0;
int map[16];
void NQueen(int limit);
int isValid(int limit, int num);

int main(){
	scanf("%d", &N);
	NQueen(0);
	printf("%d", count);
}

void NQueen(int limit){
	if(limit == N){
		count++;
		return ;
	}

	for(int i = 1; i <= N; i++){
		if(isValid(limit, i)){
			map[limit] = i;
			NQueen(limit + 1);
		}
	}
}

int isValid(int limit, int num){
	if(limit == 0)
		return 1;

	for(int i = limit - 1; i >= 0; i--){
		if(map[i] == num)
			return 0;
		if(abs(limit-i) == abs(num - map[i]))
			return 0;
	}

	return 1;
}