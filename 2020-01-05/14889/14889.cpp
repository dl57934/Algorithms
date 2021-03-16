#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;

void backTrack(int limit);
int visit[22];
int map[22][22];
int arr[22], N;
int maxAbility = 987654321;

int main(){
	
	scanf("%d", &N);

	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			scanf("%d", &map[y][x]);
		}
	}

	backTrack(0);

	printf("%d", maxAbility);
}

void backTrack(int limit){
	if(limit == N/2){
		int starkAbility = 0, linkAbility = 0;
		vector<int> member;

		for(int y = 0; y < limit; y++){
			for(int i = y+1; i < limit; i++){
				starkAbility += map[arr[y]][arr[i]] + map[arr[i]][arr[y]];
			}
		}
		
		for(int i = 0; i < N; i++)
			if(visit[i] == 0)
				member.push_back(i);
		
		for(int y = 0; y < limit; y++){
			for(int i = y+1; i < limit; i++){
				linkAbility += map[member[y]][member[i]] + map[member[i]][member[y]];
			}
		}

		if(abs(starkAbility - linkAbility) < maxAbility)
			maxAbility = abs(starkAbility - linkAbility);

		return ;
	}

	for(int i = 0; i < N; i++){
		if(visit[i] == 0 && arr[limit-1] < i){
			visit[i] = 1;
			arr[limit] = i;
			backTrack(limit+1);
			visit[i] = 0;
		}
	}
}