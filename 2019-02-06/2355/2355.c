#include <stdio.h>
#include <stdlib.h>

#define ll long long

int main(){
	ll A, B, length;
	scanf("%lld %lld", &A, &B);
	length = B - A +1;

	ll result = 0;
	if(length%2 ==0)
		result = (A+B)*(length/2);
	else
		result = (A+B)*(length/2) + (A+B)/2;
	
	printf("%lld", result);
}