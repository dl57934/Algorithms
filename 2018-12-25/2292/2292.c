#include <stdio.h>

int main(N){
	scanf("%d", &N);
	int between = 6;
	int preNum = 0, count = 1,nextNum = 7;
	for(;;){
		count++;
		if(preNum < N && N <= nextNum){
			if(N==1)
				printf("1");
			else
				printf("%d", count);
			break;
		}
		
		preNum = nextNum;
		between+=6;
		nextNum +=between;
	}
}