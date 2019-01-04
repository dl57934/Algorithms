#include <math.h>
#include <stdio.h>

void estoras(int number);

int main(){
	int M, N;
	scanf("%d %d", &M, &N);

	for(int i = M; i <= N; i++){
		if(i != 1)
			estoras(i);
	}
}

void estoras(int number){
	for(int i = 2; i<=sqrt(number); i++){
		if(number%i == 0)
			return ;
	}
	printf("%d\n", number);
}