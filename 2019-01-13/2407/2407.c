#include <stdio.h>

unsigned long long memory[102][102] = {0,};
unsigned long long bibo(int N, int M);

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%llu", bibo(n, m));
}

unsigned long long bibo(int N, int M){
	if(N == M || M ==0)
		return 1;
	else {
		if(memory[N][M] == 0)
			memory[N][M] =  bibo(N-1,M-1) + bibo(N-1, M);
		
		return memory[N][M];
	}
}