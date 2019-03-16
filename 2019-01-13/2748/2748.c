#include <stdio.h>

long long arr[100] = {0,};

long long fibo(int n){
	if(n == 0 || n == 1)
		return n;
	else {
		if(arr[n] == 0)
			arr[n] = fibo(n-1) + fibo(n-2);
		return arr[n];
	}
}

int main(){
	int n = 0;
	scanf("%d", &n);
	long long result = fibo(n);
	printf("%lld", result);
}