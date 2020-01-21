#include <stdio.h>
#include <stdlib.h>

int playerInfo[23][23] = {0,};
int N;
int playerNumbers;
int player[23];
void getPlayers(int N);
int difference = 1000000000;
int allStat = 0;

int main(){
	scanf("%d", &N);
	playerNumbers = N/2;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &playerInfo[i][j]);

	getPlayers(0);
	printf("%d", difference);
}


void getPlayers(int nowPlayer){
	if(nowPlayer==playerNumbers){
		int playerAppear[23] = {0,};
		int oneStat = 0, zeroStat=0;

		for(int i = 0; i < playerNumbers; i ++)
			playerAppear[player[i]]=1;

		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++){
				if(playerAppear[i] && playerAppear[j])			
					oneStat+=(playerInfo[i][j] + playerInfo[j][i]);
				else if(!playerAppear[i] && !playerAppear[j])
					zeroStat+=(playerInfo[i][j] + playerInfo[j][i]);
			}
		}

		if(difference > abs(oneStat - zeroStat))
			difference = abs(oneStat - zeroStat);
			
		return;
	}

	for(int i = 0; i < N; i ++){
		if(player[nowPlayer-1] < i || nowPlayer ==0){
			player[nowPlayer] = i;
			getPlayers(nowPlayer+1);
		}
	}
}