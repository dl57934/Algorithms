#include <cstdio>

#define pisano 1500000
#define mod 1000000
long long arr[1500002]={0,};


int main(){
	long long n;
	scanf("%lld", &n);
	n%=pisano;

	long long a=1, b=1, temp;

	for(int i = 1; i < n; i++){
		temp = b;
		b = (a+b)%mod;
		a = temp%mod;
	}
	printf("%lld", a);
}
