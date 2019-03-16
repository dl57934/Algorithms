#include <stdio.h>

int facotorial(int N);

int main(){
	int N,K;
	scanf("%d %d", &N, &K);
	int nFac = facotorial(N);
	int kFac = facotorial(K);
	int nMink = facotorial(N-K);

	printf("%d", nFac / (kFac*nMink));
}

int facotorial(int N){
	if(N==0)
		return 1;
	else
		return N *facotorial(N-1);
}