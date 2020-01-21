#include <stdio.h>

long long arr[1000002];
long long getTile(int N);

int main(){
	int N;
	scanf("%d", &N);
	printf("%lld", getTile(N));
}


long long getTile(int N){
	if( N== 1)
		return 1;
	else if(N==2)
		return 2;
	else {
		if(arr[N] == 0)
			arr[N] = (getTile(N-1)%15746 + getTile(N-2)%15746)%15746;
		return arr[N]%15746;
	}
}