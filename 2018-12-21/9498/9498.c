// 내코드
#include <stdio.h>  
int main(){  
	int score;  
	scanf("%d", &score);
	if(score >= 90)
		printf("A");
	else if (score >= 80)
		printf("B");	
	else if(score >= 70)
		printf("C");
	else if(score >=60)	
		printf("D");
	else 
		printf("F");		 
}

//1등 코드

int main(score){
	scanf("%d", &score);
	putchar("FFFFFFDCBA"[score/10]);
}