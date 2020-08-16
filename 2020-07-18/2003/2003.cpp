#include <cstdio>

int N, M;
int numbers[10002];

int getReavel();

int main(){
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
		scanf("%d", &numbers[i]);

	printf("%d", getReavel());
}


int getReavel(){
	int start = 0, end = 0;
	int sum = 0, count = 0;

	while(end <= N){
		if(sum < M){
			sum += numbers[end];
			end++;
		}else if(sum >= M){
			sum -= numbers[start];
			start++;
		}

		if(sum == M)
			count++;
	}

	return count;
}