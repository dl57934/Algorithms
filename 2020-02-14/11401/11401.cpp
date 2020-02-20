#include <stdio.h>

#define reminder 1000000007
#define ll long long

ll facto(ll N);
ll getSquared(ll number, ll power);

int main(){
	ll N, K;

	scanf("%lld %lld", &N, &K);
	ll differ = N-K;

	N = facto(N);
	differ = facto(differ);
	K = facto(K);

	differ = (differ*K)%reminder;
	ll result = (N* getSquared(differ, reminder-2))%reminder;

	printf("%lld", result);
}


ll facto(ll N){
	ll sum = 1;
	for (int i = 1; i <= N; ++i){
		 sum = (sum * i)%reminder;
	}
	return sum;
}

ll getSquared(ll number, ll power){
	ll answer = 1;
	while(power>0){
		if(power%2 != 0){
			answer*=number;
			answer%=reminder;
		}
		number*=number;
		number%=reminder;
		power/=2;
	}

	return answer;
}