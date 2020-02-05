#include <cstdio>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;
int N;

int arr[132][132];
int zeroCount = 0;
int oneCount = 0;

void quadTree(int startWidth, int endWidth, int startHeight, int endHeight);

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	quadTree(0, N, 0, N);
	printf("%d\n", zeroCount);
	printf("%d", oneCount);
}

void quadTree(int startWidth, int endWidth, int startHeight, int endHeight){
	int sum = 0;

	for(int i = startHeight; i < endHeight ; i++)
		for(int j = startWidth; j < endWidth; j++)
			sum+=arr[i][j];
		
	int limit = endWidth-startWidth;
	limit*=limit;
	if(sum == limit){
		oneCount+=1;
		return ;
	}
	else if(sum == 0){
		zeroCount+=1;
		return ;
	}

	int diff = (endWidth-startWidth)/2;
	quadTree(startWidth, startWidth+diff, startHeight, startHeight+diff);
	quadTree(startWidth+diff, endWidth, startHeight, startHeight+diff);
	quadTree(startWidth, startWidth+diff, startHeight+diff, endHeight);
	quadTree(startWidth+diff,  endWidth, startHeight+diff, endHeight);
}