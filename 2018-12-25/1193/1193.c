#include <stdio.h>

int main(N){
	scanf("%d", &N);
	int count =2, sameCheck=1;
	int i =1, j=2;

	if(N==1){
		printf("1/1");
		return 0;
	}

	for (;;){
		if(count == N){
			printf("%d/%d", i, j);
			break;
		}
		if(i == 1 || j == 1){
			if(i > j){
				if(i%2==0)
					i+=1;
				else 
					i-=1, j+=1;
				sameCheck = 1;
			}else if(i < j){
				if(j%2 == 0)
					i+=1, j-=1;
				else 
					j+=1;
				sameCheck=0;
			}
		}else{
				if(sameCheck)
					i-=1, j+=1;
				else 
					i+=1, j-=1;

		}
		
		count+=1;
	}

}