#include <stdio.h>

int facto(int N);

int main(){
	int N;
	scanf("%d",&N);
	printf("%d", facto(N));
}

int facto(int N){
	if(N > 0){
		return N * facto(N-1);
	}else{
		return 1;
	}
}