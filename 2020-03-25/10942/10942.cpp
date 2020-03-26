#include <cstdio>
#include <string.h>
int numbers[2002];
int dp[2002][2002];
int N, S, E, M;

void input();
int getPalin(int start, int end);

int main(){
	input();
	// for(int i = 1; i <= N; i++){
	// 	for(int x = 1; x <= N; x++){
	// 		printf("%d ", dp[i][x]);
	// 	}
	// 	printf("\n");
	// }
}

void input(){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &numbers[i]);
	scanf("%d", &M);
	for(int i = 1; i <= M; i++){
		scanf("%d %d", &S, &E);
		printf("%d\n", getPalin(S, E));
	}
}

int getPalin(int start, int end){
	if(dp[start][end] != -1){
		return dp[start][end];
	}
	if (start > end){
		return 1;
	}else if(numbers[start] != numbers[end] ){
		dp[start][end] = 0;
		return 0;
	}else{
		dp[start][end] = getPalin(start+1, end-1);
		return dp[start][end];
	}
}