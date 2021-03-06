#include <stdio.h>

int arr[10];
int N, M;
void getPermutation(int limit);

int main(){
	scanf("%d %d",&N, &M);
	getPermutation(0);
} 

void getPermutation(int limit){
	if(M == limit){
		for(int i = 0; i < M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return ;
	}

	for(int i = 1; i <= N; i++){
		arr[limit] = i;
		getPermutation(limit+1);
	}
}