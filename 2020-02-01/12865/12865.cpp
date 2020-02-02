#include <cstdio>
#include <algorithm>

using namespace std;

int arr[2][100];
int dp[103][100002];

int main(){
	int N, K;
	scanf("%d %d", &N, &K);

	for(int i = 1; i <= N; i++)
		scanf("%d %d", &arr[0][i], &arr[1][i]);
	

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <=K; j++){
			if(arr[0][i] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(arr[1][i]+ dp[i-1][j-arr[0][i]], dp[i-1][j]);
		}
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <=K; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}

	printf("%d", dp[N][K]);
}