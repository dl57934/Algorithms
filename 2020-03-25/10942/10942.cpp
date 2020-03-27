#include <cstdio>
#include <string.h>

int N, S, E, M;
int dp[2002][2002];
int data[2002];

void input();
int isPalin(int start, int end);

int main(){
	memset(dp, -1, sizeof(dp));
	input();
}

void input(){
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &data[i]);
	scanf("%d", &M);
	for(int i = 1;i <= M; i++){
		scanf("%d %d", &S, &E);
		printf("%d\n", isPalin(S, E));
	}
}


int isPalin(int start, int end){
	if(dp[start][end] != -1){
		return dp[start][end];
	}

	if(start > end)
		return 1;
	else if(data[start] != data[end]){
		dp[start][end] = 0;
		return 0;
	}else{
		dp[start][end] = isPalin(start+1, end-1);
		return dp[start][end];
	}
}