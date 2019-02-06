#include <stdio.h>

#define ll long long 

ll devide(ll N, ll F);

int main(){
	ll N, F;
	scanf("%lld %lld", &N, &F);

	ll result = devide(N, F);
	if(result < 10)
		printf("0%lld",result);
	else 
		printf("%lld",result);
}

ll devide(ll N, ll F){
	N-=N%100;
	for(int i = 0;i <= 100; i++){
		if((N+i)%F == 0)
			return i;
	}
}