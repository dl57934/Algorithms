#include <cstdio>
#include <vector>
#define ll long long

using namespace std;

int main(){
	ll M, N, inputNum;

	vector<ll> num(1000002), result(1002);
	scanf("%lld %lld", &N, &M);

	for(int i = 1; i <= N; i++){
		scanf("%lld", &inputNum);
		num[i] += inputNum + num[i-1];
	}

	for(int i = 1; i <= N; i++){
		result[num[i] % M]+=1;
	}

	ll ret = result[0];

	for(int i = 0; i < M; i++){
		ret+=(result[i] * (result[i] - 1))/2;
	}

	printf("%lld", ret);

}