#include <cstdio>

int main(){
	int N;
	scanf("%d", &N);

	for(int yLine = 1; yLine <= N; yLine++){
		for(int xLine = 0; xLine < yLine; xLine++){
			printf("*");
		}
		printf("\n");
	}

	for(int yLine = N-1; yLine >= 1; yLine--){
		for(int xLine = 0; xLine < yLine; xLine++){
			printf("*");
		}
		printf("\n");
	}
}