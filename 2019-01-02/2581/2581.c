#include <stdio.h>
#include <math.h>

int sum = 0;
int min = 10002;

int estoras(int number);
void setMin(int M, int N);

int main(){
	int M, N;
	scanf("%d %d", &M, &N);

	setMin(M, N);
	
	if(sum == 0){
		printf("-1");
	}else{
		printf("%d\n%d", sum, min);
	}
	
}

void setMin(int M, int N){
	for(int i = M; i <= N; i++){
		if( i != 1){
			if(estoras(i)){
				if(min > i)
				min = i;
			}
		}
	}
}

int estoras(int number){
	for(int i = 2; i <= sqrt(number); i++){
		if(number % i == 0){
			return 0;
		}
	}
	sum += number;
	return 1;
}