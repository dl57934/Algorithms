#include <cstdio>
#define ll long long

ll dp[1002][5][5];

int main(){
	int N;
	scanf("%d", &N);

	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	dp[1][1][0] = 1;

	for(int i = 2; i <= N; i++){
		for(int y = 0; y < 2; y++){
			for(int x  = 0; x < 3; x++){
				if(y == 0 && x == 0){
					dp[i][y][x] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % 1000000;
				}else if(y == 1 && x == 0){
					dp[i][y][x] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2] + dp[i-1][0][2]) % 1000000;
				}else if(y ==0 && x == 1){
					dp[i][y][x] = (dp[i-1][0][0]) % 1000000;
				}else if(y == 1 && x == 1){
					dp[i][y][x] = (dp[i-1][1][0]) % 1000000;
				}else if(y == 0 && x == 2){
					dp[i][y][x] = (dp[i-1][0][1]) % 1000000;
				}else if(y == 1 && x == 2){
					dp[i][y][x] = (dp[i-1][1][1]) % 1000000;
				}
			}
		}
	}
	ll result = 0;
	for(int y = 0; y < 2; y++){
		for(int x  = 0; x < 3; x++){
			result += dp[N][y][x];
			result%=1000000;
		}
		result%=1000000;
	}

	printf("%lld", result);
}