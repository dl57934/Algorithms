#include <cstdio>
#define ll long long

ll map[1002][1002];

ll NCK(int N, int K);

int main(){
	int testCase; 
	scanf("%d", &testCase);

	for(int i = 0; i < testCase; i++){
		int N, K;
		scanf("%d %d", &N, &K);
		printf("%lld\n", NCK(K, N));
	}
}

ll NCK(int N, int K){
	if(N == K)
		return 1;
	if( K == 0)
		return 1;

	if(map[N][K] == 0)
		map[N][K] = NCK(N-1, K-1) + NCK(N-1, K);

	return map[N][K];

}