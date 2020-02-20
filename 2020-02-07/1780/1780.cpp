#include <stdio.h>

int arr[2188][2188];
int N;
int zeroNumbers = 0;
int oneNumbers = 0;
int minusOneNumbers = 0;

void getPaper(int startHeight, int endHeight, int startWidth, int endWidth);

int main(){
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%d", &arr[i][j]);
		}
	}

		getPaper(0, N, 0, N);

		printf("%d\n%d\n%d", minusOneNumbers, zeroNumbers, oneNumbers);
}

void getPaper(int startHeight, int endHeight, int startWidth, int endWidth){
	long long oneCount = 0;
	long long zeroCount = 0;
	long long minusCount = 0;
	for(int i = startHeight; i < endHeight; i++){
		for(int j = startWidth; j < endWidth; j++){
			if(arr[i][j] == 1)
				oneCount+=1;
			else if(arr[i][j] == -1)
				minusCount+=1;
			else
				zeroCount+=1;
		}
	}


	int diff = endHeight-startHeight;
	long long rightDiff = diff*diff;
	diff = diff/3;


	if(oneCount == rightDiff){
		oneNumbers+=1; 
		return ;
	}else if(zeroCount == rightDiff){
		zeroNumbers+=1;
		return;
	}else if(minusCount == rightDiff){
		minusOneNumbers+=1;
		return;
	}

	getPaper(startHeight, startHeight+diff, startWidth, startWidth+diff);	
	getPaper(startHeight, startHeight+diff, startWidth+diff, endWidth-diff);	
	getPaper(startHeight, startHeight+diff, endWidth-diff, endWidth);	
	getPaper(startHeight+diff, endHeight-diff, startWidth, startWidth+diff);	
	getPaper(startHeight+diff, endHeight-diff , startWidth+diff, endWidth-diff);	
	getPaper(startHeight+diff, endHeight-diff , endWidth-diff, endWidth);	
	getPaper(endHeight-diff, endHeight, startWidth, startWidth+diff);	
	getPaper(endHeight-diff, endHeight, startWidth+diff, endWidth-diff);	
	getPaper(endHeight-diff, endHeight, endWidth-diff, endWidth);	
}