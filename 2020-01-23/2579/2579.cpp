#include <stdio.h>
#include <algorithm>

using namespace std;

int stairPoint[302] = {0,};
int firstStartStair[302] = {0 ,};
int firstContinuity = 0;

int main(){
	int N; 
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &stairPoint[i]);

	firstStartStair[0] = stairPoint[0];
	firstStartStair[1] = stairPoint[0] + stairPoint[1];
	firstStartStair[2] = max(stairPoint[2] + stairPoint[0], stairPoint[2] + stairPoint[1]);
	
	for(int i = 3; i < N; i++)
		firstStartStair[i] = max(stairPoint[i] + stairPoint[i-1] + firstStartStair[i-3], 
			stairPoint[i] + firstStartStair[i-2]);
	printf("%d", firstStartStair[N-1]);
}
