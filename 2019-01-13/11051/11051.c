#include <stdio.h>

#define P 10007
#define NOTMEMO 0

long long note[1002][1002] ={0,};

long long bino(int N, int R);

int main(){
	int N, R;
	long long result;
	scanf("%d %d", &N, &R);
	result = bino(N, R);
	printf("%lld", result%10007);
}

long long bino(int N, int R){
	if(R == N || R ==0)
		return 1;
	else {
		if(note[N][R] == NOTMEMO)
			note[N][R] = bino(N-1, R-1)%10007 + bino(N-1, R)%10007;
		return  note[N][R];
	}
}