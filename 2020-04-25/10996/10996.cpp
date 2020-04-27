#include <cstdio>

int main(){
	int N;
	scanf("%d", &N);

	if(N == 1){
		printf("*");
		return 0;
	}

	for(int yLine = 1; yLine <= N; yLine++){
		for(int xLine = 0; xLine < N; xLine++){
			if(xLine % 2==0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
		for(int xLine = 0; xLine < N; xLine++){
			if(xLine % 2==0)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}