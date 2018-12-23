#include <stdio.h>
#include <string.h>

int main(N){
	scanf("%d", &N);
	char circleX[81];
	int result [1000] = {0,};
	int last = 0;
	char lastMark;

	for(int i = 0; i < N;i++){
		scanf("%s", &circleX);
		for(int j =0; j < strlen(circleX); j++){
			if(circleX[j] == 'X'){
				last = 0;
			}else {
				last+=1;
			}
			result[i] += last;
		}
		last=0;
	}

	for(int i = 0;i < N;i++){
		printf("%d\n",result[i]);
	}
}