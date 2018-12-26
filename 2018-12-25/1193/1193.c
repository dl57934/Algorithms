#include <stdio.h>

int main(N){
	scanf("%d", &N);
	int floor=1;

	while(N-floor>0){
		N-=floor;
		floor+=1;
	}

	if(floor%2==0)
		printf("%d/%d", N, floor-N+1);
	else	
		printf("%d/%d", floor-N+1, N);
}