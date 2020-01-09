#include <stdio.h>
#include <math.h>

int main(){
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);

	if(A == B)
		printf("1");
	else 
		printf("%d", (int)(ceil((double)(V-A)/(double)(A-B)+1)));
}