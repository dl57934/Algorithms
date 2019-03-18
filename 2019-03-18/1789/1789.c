#include <stdio.h>

#define ll long long

ll s;

int main(){
	scanf("%lld", &s);
	ll i = 1;
	ll sum = 0;
	while(s >= sum){
		sum += i;
		i+=1;
	}

	printf("%lld\n", i-2);
}