#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	long long A, B, C; // A 고정 비용, B 가변 비용, C 노트북 가격

	scanf("%lld %lld %lld",&A, &B, &C);
	if(B >= C){
		printf("-1");
		return 0;
	}
	long long answer = (long long)ceil((double)abs(A)/(double)(C-B));
	
	if((A + B * answer) == C *answer)
		printf("%lld", answer+1);	
	else
		printf("%lld", answer);
}