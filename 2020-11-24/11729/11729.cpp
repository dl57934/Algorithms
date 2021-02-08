#include <cstdio>
#include <math.h>
void hanoi(int N, int start, int mid, int to){
	if(N == 1)
		printf("%d %d\n", start, to);
	else{
		hanoi(N-1, start, to, mid);
		printf("%d %d\n", start, to);
		hanoi(N-1, mid, start, to);
	}
}

int main(){
	int N;
	scanf("%d", &N);
	printf("%d\n", int(pow(2, N))- 1);
	hanoi(N, 1, 2, 3);
}