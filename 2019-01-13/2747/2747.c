#include <stdio.h>

int arr[47] ={0,};

int fibo(int n){
	if(n == 0 || n==1)
		return n;
	else {
		if(arr[n] == 0){
			arr[n] = fibo(n-1) + fibo(n-2);
		}
		return arr[n];
	}
}

int main(n){
	scanf("%d", &n);
	int result = fibo(n);
	printf("%d", result);
}