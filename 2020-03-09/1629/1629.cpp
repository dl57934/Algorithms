#include <stdio.h>

long long A, B, C;

long long mul(long long oper, long long numbers);

int main(){
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", mul(A, B)%C);
}

long long mul(long long oper, long long numbers){
	if(numbers == 0)
		return 1;

	long long temp = mul(oper, numbers/2)%C;

	if(numbers % 2 ==0){
		return (temp%C * temp%C) % C;
	}else{
		return (oper * temp%C * temp%C) % C;
	}
}


#include <cstdio> 
#include <math.h> 
long long getPower(long long A, long long B, long long mod); 
int main(){ 
	long long A, B, C; 
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld", getPower(A, B, C)%C); 
	} 
long long getPower(long long A, long long B, long long mod){ 
		if(B == 0) return 1; 
		long long temp = (getPower(A, B/2, mod)); 
		if(B % 2 == 0) 
			return (temp%mod * temp%mod) % mod; 
		else 
			return (temp%mod * temp%mod * A)%mod; 
}

// long long mul(){
// 	long long temp = 1;
// 	while( B > 0){
// 		if(B % 2 == 1){
// 			temp*=A;
// 			temp%=C;
// 		}
// 		A*=A;
// 		A%=C;
// 		B/=2;
// 	}
// 	return temp;
// }