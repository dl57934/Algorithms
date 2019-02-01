#include <stdio.h>
#include <math.h>
void hanoi(int n, int from, int by, int to);

int main(){
	int K;
	scanf("%d", &K);
	printf("%d\n", (int)pow(2, K)-1);
	hanoi(K, 1, 2, 3);
}

void hanoi(int n, int from, int by, int to){
	if(n == 1)
		printf("%d %d\n",from, to);	
	else {
		hanoi(n-1, from, to, by);
		printf("%d %d\n",from, to);	
		hanoi(n-1, by, from, to);
	}
}