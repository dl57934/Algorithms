#include <stdio.h>

int main(){
	long long n= 0;
	scanf("%lld", &n);
	long long f1 = 0, f2 = 1;
	long long result = 0;

	for(int i = 1; i < n%1500000; i++){
		result = (f1 + f2)%1000000;
		f1 = f2;
		f2 = result;
	}
	if(n%1500000 ==0 ||n%1500000 ==1 )
		printf("%lld", n%1500000);
	else
		printf("%lld", result);
}