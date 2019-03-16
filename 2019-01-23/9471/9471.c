#include <stdio.h>

int M;

long long arr[1000000]={0,};
long long temp[1000000]={0,};
long long fibo(int N);

int main(){
	int P, N;
	scanf("%d", &P);

	for(int i = 0; i<P; i++){
		scanf("%d %d", &N, &M);
		fibo(100);
		for(int i = 0; i < 100; i++)
			printf("%d: %lld\n", i, arr[i]);
	}
}

long long fibo(int N){
	if(N==0)
		return 0;
	else if (N==1)
		return 1;
	else {
		if(arr[N] == 0)
			arr[N] = (fibo(N-1) %N + fibo(N-2)%N)%N;
		return arr[N]%4;
	}
}