#include <cstdio>

void backTrack(int limit);
int N, M;
int visited[9];
int arr[9];

int main(){	
	scanf("%d %d", &N, &M);
	backTrack(0);
}


void backTrack(int limit){
	if(limit == M){
		for(int i = 0; i < limit; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}

	for(int i = 1; i <= N; i++){
		if(visited[i] == 0){
			arr[limit] = i;
			visited[i]= 1;
			backTrack(limit+1);
			visited[i]= 0;
		}
	}
}