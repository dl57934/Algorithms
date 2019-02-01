#include <stdio.h>

int main(){
	int all, hansu, jimin;
	int round = 0;
	scanf("%d %d %d", &all, &jimin, &hansu);
	jimin-=1, hansu-=1;
	while(jimin!=hansu){
		jimin/=2;
		hansu/=2;
		round+=1;
	}
	printf("%d", round);
}
