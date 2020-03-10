#include <cstdio>
#define ll long long
#define mod 1000000007

ll facto(ll start, ll end);
ll getPower(ll oper, ll numbers);

int main(){
	ll N, K;
	ll B = 1;
	ll A = 1;
	scanf("%lld %lld", &N, &K);
	B = facto(B, K);
	B = facto(B, N-K);
	B = getPower(B, mod-2);
	A = facto(A, N);
	printf("%lld", (A*B)%mod);
}

ll facto(ll temp, ll end){
	for(int i = 1; i <= end; i++)
		temp = (temp*i)%mod;
	return temp%mod;
}

ll getPower(ll oper, ll numbers){
	ll temp = 1;
	while(numbers > 0){
		if(numbers%2==1){
			temp*=oper;
			temp%=mod;
		}
		oper*=oper;
		oper%=mod;
		numbers/=2;
	}
	return temp%mod;
}