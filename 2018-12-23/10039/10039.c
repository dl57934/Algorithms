#include <stdio.h>

int main(){
	int result=0, score=0;
	for(int i = 0 ; i<5;i++){
		scanf("%d", &score);
		if(score < 40)
			result+=40;
		else
			result+=score;
	}
	printf("%d",result/5);
}