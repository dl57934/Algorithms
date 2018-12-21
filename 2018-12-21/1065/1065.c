#include <stdio.h>

int getOneNumber(int N);

int main(N){
	scanf("%d", &N);
	printf("%d",getOneNumber(N));
}

int getOneNumber(int N){
	int count = 0, number = 0;
	int hun, ten, one;
	for (int i = 1; i<=N;i++){
		if(i < 100)
			count+=1;
		else{
			number = i;
			hun = number/100; 
			number -= hun*100;
			ten = number /10;
			one = number %10;
			if(hun - ten == ten - one)
				count += 1;
		}
	}
	return count;
}