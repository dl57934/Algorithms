#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;

int memeory[102];
int timer[102];
int dp[102][10002];
int result = 100002;

void input();
void getMinTime();

int main(){
	input();
	getMinTime();
	printf("%d", result);
}

void input(){
	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; i++){
		scanf("%d", &memeory[i]);
	}
	for(int i = 1; i <= N; i++){
		scanf("%d", &timer[i]);
	}
}

void getMinTime(){
	for(int m = 1; m <= N; m++){
		for(int t = 1; t <= 10000; t++){
			if(t < timer[m]){
				dp[m][t] = dp[m-1][t]; 
			}else{
				dp[m][t] = max(dp[m-1][t], memeory[m] + dp[m-1][t-timer[m]]); 
				if(dp[m][t] >= M && result > t){
					result = t;
				}
			}
		}
	}
}