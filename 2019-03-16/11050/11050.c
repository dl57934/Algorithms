#include <stdio.h>

int saveMidValue[12][12]={0 ,};

int nCk(int N, int K);

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", nCk(N, K));
}

int nCk(int N, int K){
	if(N == K|| K == 0)
		return 1;
	else {
		if(saveMidValue[N][K] == 0)
			saveMidValue[N][K] = nCk(N-1, K-1) + nCk(N-1, K);
		return saveMidValue[N][K];
	}
}