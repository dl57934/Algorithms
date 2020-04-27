#include <cstdio>

int main(){
	int N;
	scanf("%d", &N);
	int start = 2 * N - 1;
	int jump = 0;
	for(int i = 1; i <= N; i++){

		for(int s = 0; s < jump; s++)
			printf(" ");

		for(int j = 1; j <= start; j++){
			printf("*");
		}
		start-=2;
		jump+=1;
		printf("\n");
	}
	jump = N-2;
	start = 3;

	for(int i = 1; i < N; i++){

		for(int s = 0; s < jump; s++)
			printf(" ");

		for(int j = 1; j <= start; j++){
			printf("*");
		}
		start+=2;
		jump-=1;
		printf("\n");
	}
}