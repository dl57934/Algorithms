#include <cstdio>
#define ll long long
int main(){
	ll V, A, B;

	scanf("%lld %lld %lld", &A, &B, &V);
	ll diff = A - B;
	ll n1, n2;

	n1 = (V - A + diff)/diff + ((V - A + diff)%diff == 0? 0 : 1);	
	n2 = (V - B + diff)/diff + ((V - B + diff)%diff == 0? 0 : 1);
	

	if(n1 < n2)
		printf("%lld", n1);
	else
		printf("%lld", n2);
}