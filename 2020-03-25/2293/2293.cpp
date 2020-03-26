#include <cstdio>

int N, K;

int coin[102];
int dp[10002];

void input();
void coinCount();

int main(){
	input();
	coinCount();
	printf("%d", dp[K]);
}

void input(){
	scanf("%d %d", &N, &K);

	for(int i = 1; i <= N; i++)
		scanf("%d", &coin[i]);
}

void coinCount(){
	for(int i = 1; i <= N; i++){
		for(int won = 1; won <= K; won++){
			if(won > coin[i]){
				int difference = won-coin[i];
				dp[won]+= dp[difference];	
			}else if( won == coin[i]){
				dp[won]+=1;
			}
		}
	}
}