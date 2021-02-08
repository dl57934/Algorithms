#include <cstdio>

int coin[12];

int main(){
	int N, K;
	int count = 0;
	scanf("%d %d", &N, &K);

	for(int i = 0; i < N; i++)
		scanf("%d", &coin[i]);

	for(int i = N-1; i >= 0; i--){
		if(K >= coin[i]){
			count+=K/coin[i];
			K -= (K/coin[i]) * coin[i];
		}else if(K == 0)
			break;
	}

	printf("%d", count);
}