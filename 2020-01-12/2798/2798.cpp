#include <stdio.h>

int card[1020];

int main(){
	int N, M; // N 카드 수 M 카드 크기 제한
	
	int count=0, max = 0;

	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
		scanf("%d", &card[i]);
	
	for(int i = 0; i < N; i++)
		for(int j = i+1; j< N; j++)
			for (int k = j+1; k<N;k++){
				if(card[i] + card[j] + card[k] <= M && card[i] + card[j] + card[k] > max){
					max = card[i] + card[j] + card[k];
				}
			}

	printf("%d", max);
}

