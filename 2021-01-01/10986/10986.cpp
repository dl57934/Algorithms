#include <cstdio>
#include <algorithm> 
#include <vector> 

using namespace std; 

#define ll long long

ll result[1002];
ll res;
int main(){ 
	ll N, M;
	vector<ll> v(1000002); 
	
	scanf("%lld %lld", &N, &M);
	int num;
	for(int i = 1; i <= N; i++){
		scanf("%d", &num);
		v[i] = v[i-1] + num;
	}

	for(int i = 1; i <= N; i++){
		result[v[i] % M] += 1;
	}

	for(int i = 0; i < M; i++){
		if(i == 0){
			res += result[i];
		}

		res += (result[i] * (result[i] - 1)) / 2;
	}


	printf("%lld", res);

	return 0; 
}