#include <stdio.h>

#define ll long long
#define MOD 1000000009

ll arr[1000003]={0, };

int main(){
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for(ll i = 4; i <= 1000000; i++)
		arr[i] = (arr[i-1]%MOD + arr[i-2]%MOD + arr[i-3]%MOD)%MOD;
	
	int T, testCase;

	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		scanf("%d", &testCase);
		printf("%lld\n", arr[testCase]);
	}

}
