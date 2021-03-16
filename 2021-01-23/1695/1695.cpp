#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int arr[5002], dp[5002][5002];
int maxValue = 0;

int palin(int S, int E){
	if(S >= E)
		return 0;

	if(dp[S][E] >= 0)
		return dp[S][E];

	if(arr[S] == arr[E]){
		dp[S][E] = palin(S+1, E-1);
		return dp[S][E];
	}else{
		dp[S][E] = min(palin(S+1, E), palin(S, E-1)) + 1;
		return dp[S][E];
	}
}

int main(){
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	palin(0, N-1, 0);

	printf("%d", dp[0][N-1]);	
}	