#include <stdio.h>

int N, M;
int arr[10];
int visited[10];
void getPermutation(int limit);
int isUpSide();

int main(){
	scanf("%d %d", &N,  &M);
	for(int i =  0; i < N; i++)
		arr[i] = i+1;
	getPermutation(0);
}

int isUpSide(){
	for(int i = 1; i < M; i++)
		if(arr[i-1] > arr[i])
			return 0;
	return 1;
}

void getPermutation(int limit){
	if(M == limit){
		if(isUpSide() == 1){
			for(int i = 0; i < M; i++)
				printf("%d ", arr[i]);
			printf("\n");
		}
		return ;
	}

	for(int i = 1; i <= N; i++){
		if(visited[i] == 0){
			visited[i] = 1;
			arr[limit] = i;
			getPermutation(limit+1);
			visited[i] = 0;
		}
	}
}