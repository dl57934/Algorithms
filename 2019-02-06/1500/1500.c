#include <stdio.h>

#define ll long long

ll maxMulti(ll S, ll K);

int main(){
	ll S, K;
	scanf("%lld %lld", &S, &K);
	printf("%lld", maxMulti(S, K));
}

ll maxMulti(ll S, ll K){
	ll result = 1;
	for(int i = K; i >= 1; i--){
		result*=S/i;
		S-=S/i;
	}
	return result;
}