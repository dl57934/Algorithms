#include <stdio.h>

main(){
	int A, B, C;
	scanf("%d%d%d",&A,&B,&C);
	printf("%d %1$d %d %2$d",(A+B)%C,(A*B)%C);
}