#include <cstdio>

long long arr[7][7];
long long temp[7][7];
long long N, B;

void strassen(int start, int end);

int main(){
	int count = 1;
	scanf("%d %d", &N, &B);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			strassen(i, j);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%d ", temp[i][j]);
		}
		printf("\n");
	}
}

void strassen(int start, int end){
	for(int i = 0; i < N; i++)
		temp[start][end] += arr[start][i] * arr[i][end];
}