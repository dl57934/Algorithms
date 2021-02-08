#include <cstdio>

long long map[92][4];



int N;
long long count;
void dp(int limit){

	map[limit][0] = map[limit-1][0] + map[limit-1][1];
	map[limit][1] = map[limit-1][0];

	if(limit == N){
		return ;
	}
		
	dp(limit+1);
}

int main(){
	map[1][0] = 0;
	map[1][1] = 1;
	scanf("%d", &N);
	if( N == 1)
		printf("%d", 1);
	else{
		dp(2);
		printf("%lld", map[N][0] + map[N][1]);
	}
}