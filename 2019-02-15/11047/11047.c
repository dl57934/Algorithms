#include <stdio.h>

int coins[11]={0, };

int main(){
	int N, K;
	int result = 0;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%d", &coins[i]);
	

	for(int i = N-1; i >=0; i--){
		if(K >= coins[i]){
			result += K/coins[i];
			K=K%coins[i];
		}else if(K==0){
			break;
		}
	}
	printf("%d", result);
}