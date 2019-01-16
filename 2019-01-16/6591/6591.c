#include <stdio.h>

long long factorial(int n, int r);

int main(){
	long long n=1, k=1;

	while(1){
		scanf("%lld %lld", &n, &k);
		if(n==0 && k==0)
			break;
		long long result = factorial(n, k);
		printf("%lld\n", result);
	}
}

long long factorial(int n, int r){
    if (r == 0 || n == r)
        return 1;

    long long q = 1;
    for (int i = 1; i <= r; i++)
        q = q * n-- / i;

    return q;
}