#include <stdio.h>
#include <math.h>

void estoras(int num);

int main(){
	int M, N;
	scanf("%d %d", &M, &N);
	for(int i = M; i <= N; i ++){
		if(i != 1)
			estoras(i);
	}
}

void estoras(int num){
	for(int i = 2; i <= sqrt(num); i++){
		if(num % i == 0)
			return ;
	}
	printf("%d\n", num);
}