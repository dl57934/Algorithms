#include <cstdio>

int NCK(int N, int K);

int arr[1001][1002];

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", NCK(N, K));
}

int NCK(int N, int K){
	if (N == K || K == 0)
		return 1;
	else if(K == 1)
		return N;


	if(arr[N][K] == 0){
		arr[N][K] = (NCK(N-1, K - 1)%10007 + NCK(N-1, K)%10007)%10007;
	}
	return arr[N][K] % 10007;

}