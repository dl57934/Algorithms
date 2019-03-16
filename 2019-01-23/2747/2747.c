#include <stdio.h>

unsigned long long arr[1000005] = {0, };
unsigned long long fibo(unsigned long long N);

int main(){
	unsigned long long N;
	scanf("%lld", &N);
	printf("%lld", fibo(999999)%1000000);
}

unsigned long long fibo(unsigned long long N){
	if (N == 0 )
		return 0;
	else if(N==1)
		return 1;
	else{
		if(arr[N] == 0)
			arr[N] = (fibo(N-1)%1000000+fibo(N-2)%1000000)%1000000;
		return arr[N];
	} 
}