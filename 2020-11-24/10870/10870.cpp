#include <cstdio>

int map[22];

int fibo(int N){
	if(N == 0)
		return 0;
	else if(N == 1)
		return 1;
	if(map[N] != 0)
		return map[N];
	else {
		map[N] = fibo(N - 1) + fibo(N - 2);
		return map[N];
	}
	
}

int main(){
	int N;
	scanf("%d", &N);
	printf("%d", fibo(N));
}