#include <stdio.h>

long long getWavePermutation(int n);
long long arr[102];

int main(){
	int T, n;
	scanf("%d", &T);
	for(int i=0; i < T; i++){
		scanf("%d", &n);
		printf("%lld\n", getWavePermutation(n));
	}

}

long long getWavePermutation(int n){
	if(n == 1 || n == 2 || n==3)
		return 1;
	else{
		if(arr[n] == 0)
			arr[n] = getWavePermutation(n-2) + getWavePermutation(n-3);
		return arr[n];
	}
}