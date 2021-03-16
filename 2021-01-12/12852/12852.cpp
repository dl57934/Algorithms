#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> result;
int dp[1000020], N;

int main(){
	scanf("%d", &N);

	dp[1] = 0, dp[2] = 1, dp[3] = 1;

	for(int i = 4; i <= N; i++){
		if(i % 3 == 0){
			if(i % 2 == 0){
				dp[i] = min(min(dp[i/3], dp[i/2]), dp[i-1]) + 1;
			}else{
				dp[i] = min(dp[i/3], dp[i-1]) + 1;
			}
		}else if(i % 2 == 0){
			dp[i] = min(dp[i/2], dp[i-1]) + 1;
		}else{
			dp[i] = dp[i-1] + 1;
		}
	}

	printf("%d\n", dp[N]);
	
	while(N>=1){
		printf("%d ", N);
		if(N % 3 == 0){
			if(N % 2 == 0){

				int num = min(min(dp[N/3], dp[N/2]), dp[N-1]);
				if(num == dp[N/3])
					N = N/3;
				else if(num == dp[N/2])
					N = N/2;
				else
					N = N -1;
			}else{
				int num = min(dp[N/3], dp[N-1]);
				if(num == dp[N/3])
					N = N/3;
				else if(num == dp[N-1])
					N = N-1;
			}
		}else if(N % 2 == 0){
			int num = min(dp[N/2], dp[N-1]);
				if(num == dp[N/2])
					N = N/2;
				else if(num == dp[N-1])
					N = N-1;
		}else{
			N = N-1;
		}
	}

}