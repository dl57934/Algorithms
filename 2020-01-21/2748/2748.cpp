#include <stdio.h>

long long fibo[100] = { 0, };
long long getFibo(int n);


int main(){
	int n;
	scanf("%d", &n);
	printf("%lld", getFibo(n));
}

long long getFibo(int n){
	//memozation
	// if(n == 0)
	// 	return 0;
	// else if(n == 1 || n==2)
	// 	return 1;
	// else {
	// 	if(fibo[n] == 0)
	// 		fibo[n] = getFibo(n-1) + getFibo(n-2);
	// 		return fibo[n];
	// }

	//bottomUp
	fibo[1] = fibo[2] = 1;
	for(int i=3; i<=n; i++)
		fibo[i] = fibo[i-2] + fibo[i-1];
	return fibo[n];
}