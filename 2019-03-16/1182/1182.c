#include <stdio.h>

#define ll long long

ll arr[22];
int count = 0;
int N, S = 0;
void getS(int basicNum ,int appendIndex);

int main(){
	scanf("%d %d", &N, &S);
	for(int i = 0; i  < N; i++)
		scanf("%lld", &arr[i]);

	for(int i = 0; i < N; i++)
		if(arr[i] == S)
			count+=1;

	for(int i = 0; i < N-1; i++)
		for(int j = i+1; j < N; j++)
			getS(arr[i], j);
	printf("%d\n", count);

}

void getS(int basicNum ,int appendIndex){
	basicNum += arr[appendIndex];
	if(basicNum == S)
		count+=1;
	
	for(int i = appendIndex+1; i < N; i++){
		getS(basicNum, i);
	}
}

