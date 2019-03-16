#include <stdio.h>

#define ll long long

ll N[102];
ll getGcd(ll big, ll small);
ll isBig(ll origin, ll compare);
void calculate(ll origin,ll newValue);
ll gcd = 0;

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%lld", &N[i]);
		if (i == 1)
			calculate(N[0], N[1]);
		if(i > 1)
			calculate(gcd, N[i]);
	}
	// for(int i = 0; i < T; i++){
		
	// }

	printf("%lld", gcd);	
}

void calculate(ll origin,ll newValue){
	if(isBig(origin, newValue))
		gcd = getGcd(origin, newValue);
	else 
		gcd = getGcd(newValue, origin);
}

ll isBig(ll origin, ll compare){
	return origin > compare;
}

ll getGcd(ll big, ll small){
	if(small==0)
		return big;
	else
		return getGcd(small, big%small);
}
