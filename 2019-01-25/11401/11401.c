#include <stdio.h>

#define ll long long 
#define mod 1000000007

ll facto(ll operation, ll limit);
ll calculatePower(ll operation);

int main(){
	ll N, K;
	scanf("%lld %lld", &N, &K);
	ll A = facto(1, N);
	ll B = facto(1, K);
	B = facto(B, N-K);
	printf("%lld", (A*calculatePower(B))%mod);
}

ll facto(ll operation, ll limit){
	for(int i = 1; i <= limit; i++){
		operation*=i;
		operation%=mod;
	}
	return operation%mod;
}

ll calculatePower(ll operation){
	ll limit = mod-2;
	ll result = 1;
	while(limit>0){
		if(limit%2!=0){
			result*=operation;
			result%=mod;
		}
		operation*=operation;
		operation%=mod;
		limit/=2;
	}
	return result%mod;
}






