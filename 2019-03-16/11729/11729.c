#include <stdio.h>
#include <math.h>

void hanoi(int from, int by, int to, int n);

int main(){
	int N;
	scanf("%d", &N);
	printf("%d\n",(int)pow(2, N)-1);
	hanoi(1, 2, 3, N);
}

void hanoi(int from, int by, int to, int n){
	if(n == 1)
		printf("%d %d\n", from, to);
	else{
		hanoi(from, to, by, n-1);
		printf("%d %d\n", from, to);
		hanoi(by, from, to, n-1);
	}
}