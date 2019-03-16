#include <stdio.h>
#include <math.h>

void goldBarh(int num);
int estoras(int num);
void init();

int min = 50000;
int small = 0, big = 0;

int main(N){
	int num;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		goldBarh(num);
		printf("%d %d\n", small, big);
		init();
	}
}

void init(){
	min = 50000;
	small = 0, big = 0;
}

void goldBarh(int num){
	for(int i = 2; i <= num/2; i++){
		if(estoras(num-i) && estoras(i)){
			if (min > num - 2*i ){
				small = i;
				big = num-i;
			}
		}
	}
}

int estoras(int num){
	for(int i = 2; i<=sqrt(num); i++)
		if(num % i == 0)
			return 0;
	return 1;	
	
}