#include <stdio.h>
#define ll long long
#define mod 1000000007

ll getFibo(ll num);
ll getGcd(ll big, ll small);
int main(){
	ll n, m, gcd;
	scanf("%lld %lld", &n, &m);
	
	if(m > n)
		gcd = getGcd(m, n);
	else
	 	gcd = getGcd(n, m);	 
	printf("%lld", getFibo(gcd%mod));
}


ll getFibo(ll num){
	ll f1= 0, f2=1;
	for(int i = 0; i < num; i++){
		ll temp = f2%mod;
		f2 = (f1+f2)%mod;
		f1 = temp%mod;
	}
	return f1;
}
ll getGcd(ll big, ll small){
	if(small == 0 )
		return big;
	else 
		return getGcd(small, big%small);
}