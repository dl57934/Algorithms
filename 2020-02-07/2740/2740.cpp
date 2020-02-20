#include <stdio.h>

int A[102][102], B[102][102];
int result[102][102];
int N, M;
int K;

void calculate(int start, int end);

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
		scanf("%d", &A[i][j]);

	scanf("%d %d", &M, &K);
	for(int i = 0; i < M; i++)
		for(int j = 0; j < K; j++)
			scanf("%d", &B[i][j]);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < K; j++)
			calculate(i, j);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < K; j++){
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
}

void calculate(int start, int end){
	for(int i = 0; i < M; i++)
		result[start][end] += (A[start][i] * B[i][end]);
}