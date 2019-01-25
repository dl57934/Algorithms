#include <stdio.h>

#define ll long long 

ll nCk(ll N, ll K);
int isZero(ll N, ll K);

int main(){
	ll N, K;
	while(1){
		scanf("%lld %lld", &N, &K);	
		if(isZero(N, K))
			break;
		printf("%lld\n", nCk(N, K));
	}
}

int isZero(ll N, ll K){
	return N ==0 && K==0;
}

ll nCk(ll N, ll K){
	ll result = 1;

	if (N==K || K==0)
		return 1;
	if(K > N-K)
		K = N-K;
	for(int i =1; i<=K; i++){
		result = (result * N--)/i; 
	}
	return result;
}


