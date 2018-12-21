#include <stdio.h>

int main(){
	int N, C ;
	float avg, score[1001], sum, largeNum;
	scanf("%d", &C);
	for (int test = 0; test<C; test++){
		scanf("%d", &N);
		sum = 0;
		largeNum = 0;
		for(int person = 0; person < N;person++){
			scanf("%f", &score[person]);
			sum += score[person];
		}
		avg = sum/N;
		for(int person = 0; person < N;person++){
			if(score[person] > avg)
				largeNum +=1;
		}
		printf("%.3f%%\n", (largeNum/N)*100);
	}
}