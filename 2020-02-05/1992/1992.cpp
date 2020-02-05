#include <cstdio>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;
int N;

char arr[66][66];
string result;

void quadTree(int startWidth, int endWidth, int startHeight, int endHeight);

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%s", &arr[i]);

	
	quadTree(0, N, 0, N);

	printf("%s", result.c_str());
}

void quadTree(int startWidth, int endWidth, int startHeight, int endHeight){
	int sum = 0;

	for(int i = startHeight; i < endHeight ; i++)
		for(int j = startWidth; j < endWidth; j++)
			sum+=(arr[i][j]-'0');
		
	int limit = endWidth-startWidth;
	limit*=limit;
	if(sum == limit){
		result.push_back('1');
		return ;
	}
	else if(sum == 0){
		result.push_back('0');
		return ;
	}

	int diff = (endWidth-startWidth)/2;

	result.push_back('(');
	quadTree(startWidth, startWidth+diff, startHeight, startHeight+diff);
	quadTree(startWidth+diff, endWidth, startHeight, startHeight+diff);
	quadTree(startWidth, startWidth+diff, startHeight+diff, endHeight);
	quadTree(startWidth+diff,  endWidth, startHeight+diff, endHeight);
	result.push_back(')');
}