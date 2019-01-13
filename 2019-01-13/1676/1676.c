#include <stdio.h>

void decomposition(int num);

int twoCount = 0;
int fiveCount = 0;

int main(){
	long long N;
	long long result = 1;
	scanf("%lld", &N);

	for(int i = 2; i<=N; i++)
		decomposition(i);	
	
	if(twoCount > 0 && fiveCount > 0){
		if(twoCount > fiveCount)
			printf("%d", fiveCount);
		else
			printf("%d", twoCount);
	}else {
		printf("0");
	}
	
}

void decomposition(int num){
	int devide = 2; 
	while( devide<=num){
		if(num % devide == 0){
			if(devide == 2){
				twoCount+=1;
				num/=2;		
			}else if(devide==5){
				fiveCount+=1;
				num/=5;
			}
		}else{
			if(devide == 2)
				devide = 5;	
			else 
				break;
		}
	}
}