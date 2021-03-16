#include <cstdio>
#include <algorithm>

using namespace std;

int member[10002];
int dp[10002][502][3];
int N, M;

void solve(){
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= M; j++){
			for(int choice = 0; choice < 2; choice++){
				if(choice == 0){
					dp[i][j][choice] = 
				}else{
					if(j == 0){
						dp[i][j] = max(dp[i-1][j], dp[i-1][j + 1]);
					}else if(dp[i-1][j-1] + member[i] > dp[i-1][j] && N - i >= j){
						dp[i][j] = dp[i-1][j-1] + member[i];
					}else{
						dp[i][j] = dp[i-1][j];
					}
				}
			}
		}
	}
}


int main(){
	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; i++)
		scanf("%d", &member[i]);

	solve();

	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= M; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("%d", dp[N][M]);
}