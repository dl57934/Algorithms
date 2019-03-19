#include <stdio.h>
#include <stdlib.h>

int q[20]={0,};
int size;
int count = 0;

void nQueen(int q[], int N);
int promising(int q[], int N);

int main(){
	scanf("%d", &size);
	nQueen(q, 0);
	printf("%d", count);
}



void nQueen(int q[], int N){
	if(N == size)
		return ;
	else{
		for(int i = 0; i < size; i++){
			q[N] = i;
			if(promising(q, N)) nQueen(q, N+1);
		}
	}
}

int promising(int q[], int N){
	for(int i = 0; i < N; i++){
		if(q[N] == q[i])
			 return 0;
		if(abs(q[N] - q[i]) == abs(N-i))
			return 0;	
	}
	return 1;
}