#include <cstdio>

int arr[45] = {0, };
int one[45] = {0, 1};
int zero[45] = {1, 0};
int fibo(int N);

int main(){
	int T, N;
	one[1] = 1;
	zero[0] = 1;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d", &N);
		fibo(N);
		printf("%d %d\n",zero[N], one[N]);
	}
}

int fibo(int N){
	if(N==0){
		return 0;
	}
	else if(N==1){
		return 1;
	}
	else{
		if(arr[N] == 0){
			arr[N] = fibo(N-1) + fibo(N-2);
			one[N] = one[N-1] + one[N-2];
			zero[N] = zero[N-1]+zero[N-2];	
		}
		return arr[N];
	}
}