#include <stdio.h>

int main(N){
	scanf("%d", &N);
	int originalNum = N;
	int one=0, ten=0, count=0;
	for(;;){
		ten = N%10;
		one = (N/10+N%10)%10;
		N = ten*10+one;
		count+=1;
	}
		printf("%d", count);
}