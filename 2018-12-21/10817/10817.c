#include <stdio.h>

int main(){
	int A,B,C;
	int max, min, sec;
	scanf("%d %d %d", &A, &B, &C);
	if( (A >= B && B >= C) || (C >= B && B >= A))
		printf("%d", B);
	else if((A >= C && C >= B) || (B >= C && C >= A))
		printf("%d", C);
	else
		printf("%d",A);
	
}