#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;

int app[103][2]; // 0 메모리 1 시간
int dp[103][100001];
int result = 102;

void input();
void getTime();

int main(){
	input();
	getTime();
	printf("%d", result);
}

void input(){
	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; i++)
		scanf("%d", &app[i][0]);
	for(int i = 1; i <= N; i++)
		scanf("%d", &app[i][1]);
}

void getTime(){
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= 100; j++){
			if(app[i][1] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				if(dp[i-1][j - app[i][1]] + app[i][0] >= M){
					if(result > j)
						result = j;
				}
				dp[i][j] = max(dp[i-1][j], dp[i-1][j - app[i][1]] + app[i][0]);
			}
		}
	}
}