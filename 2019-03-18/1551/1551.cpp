#include <stdio.h>

int arr[22];

int main(){
	int N, K;
	scanf("%d %d", &N, &K);

	for(int i = 0; i < N; i++)
		scanf("%d,", &arr[i]);
	

	for(int i =0; i < K; i++)
		for(int j = 1; j <= N-1; j++)
			arr[j-1]=arr[j] - arr[j-1];
		

	for(int i =0; i < N-K; i++){
		if(i == N-K-1)
			printf("%d", arr[i]);
		else
			printf("%d,", arr[i]);
	}
}