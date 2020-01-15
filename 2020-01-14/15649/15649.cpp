#include <stdio.h>

void getPermutation(int limit);

int arr[10];
int visited[10] = { 0,};
int N, M;
int main(){
	
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		arr[i] = i+1;
	getPermutation(0);
}

void getPermutation(int limit){
	if( M == limit){
		for(int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}

	for(int i = 1; i <= N; i++)
		if(visited[i] == 0){
			visited[i] = 1;
			arr[limit] = i;
			getPermutation(limit+1);
			visited[i] = 0;
		}		
	
}