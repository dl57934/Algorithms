#include <stdio.h>

int isBreak(int n, int k);
long long nCk(long long n, long long k);

int main(){
	long long n, k;
	for(;;){
		scanf("%lld %lld", &n, &k);
		if(isBreak(n, k))
		break;	
		printf("%lld\n", nCk(n, k));
	}
}

int isBreak(int n, int k){
	return n==0 && k==0;
}

long long nCk(long long n, long long k){
	if(n == k || k == 0)
		return 1;

	if (k > n-k)
		k = n-k;
	long long sum = 1;
	for(int i = 1; i <=k; i++){
		sum = ((n-(i-1))*sum)/i;
	}
	return sum;
}