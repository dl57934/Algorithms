#include <stdio.h>

int gcd(int a, int b);

int main(){
	int N, M;
	int operation;
	int gcdNum = 0;
	scanf("%d", &N);

	for(int i =0; i < N; i++){
		
	}
	printf("%d", gcdNum);
}

int gcd(int a, int b){
	if(b==0)
		return a; 
	return gcd(b, a%b);
}

int bigger(int a, int b){
	return a>b;
}