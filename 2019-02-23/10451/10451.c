#include <stdio.h>

int arr[1002][1002];
int step = 0;

void dfs(int x, int y);

int main(){
	int T, N;
	scanf("%d", &T);
	int to;
	for(int i = 0; i < T; i++){
		scanf("%d", &N);
		for(int j = 1; j <= N; j++){
			scanf("%d", &to);
			arr[j][0] = to;
		}

		for(int k = 1; k <= N; k++)
			if(arr[k][0]!=0)
				dfs(k, arr[k][0]);
		
		printf("%d\n", step);
		step=0;
	}

	
}

void dfs(int x, int y){
	arr[x][0] = 0;
	
	if(arr[y][0] !=0)
		return dfs(y, arr[y][0]);
	else if(arr[y][0] ==0)
		step+=1; 
}