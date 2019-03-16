#include <stdio.h>
#include <math.h>
unsigned long long bibo(int n, int k);

unsigned long long memo[102][102] = {0, };

int main(){
	int n = 1, k = 1;
	int limit = pow(2, 31);
	unsigned long long result;

	while(1){
		scanf("%d %d", &n, &k);
		if(n==0 && k==0 )
			break;
		result = bibo(n, k);
		if(result < limit)
		  printf("%llu\n", result);
	}
}

unsigned long long bibo(int n, int k){
	if(n==k || k ==0)
		return 1;
	else{
		if(memo[n][k] == 0)
			memo[n][k] = bibo(n-1, k-1) + bibo(n-1, k);
		return memo[n][k];
	}
}