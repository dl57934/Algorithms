#include <cstdio>
#define ll long long

int main(){
	ll N;
	ll wall = 1, appender = 6, line = 1;
	scanf("%lld", &N);

	while(wall < N){
		wall+=appender;
		appender+=6;
		line+=1;
	}	

		printf("%lld", line);
	
}