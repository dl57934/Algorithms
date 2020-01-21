#include <stdio.h>

int N, M;
int arr[10];

void getPermutation(int limit);

int main(){
	scanf("%d %d", &N, &M);
	getPermutation(0);
}

void getPermutation(int limit){
	if(limit == M){
		for(int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return ;
	}


	for(int i = 0; i < N; i++){
		if(arr[limit-1] < i+1 || limit == 0){
			arr[limit] = i+1;
			getPermutation(limit+1);
		}
	}
}