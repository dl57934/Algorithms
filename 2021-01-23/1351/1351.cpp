#include <cstdio>
#include <map>
#include <string>
using namespace std;

#define ll long long

map<string, ll> mp;

ll getNum(ll num);
ll N, P, Q;

int main(){
	scanf("%lld %lld %lld", &N, &P, &Q);
	printf("%lld", getNum(N));
}


ll getNum(ll num){
	if(num == 0)
		return 1;

	if(mp.find(to_string(num)) != mp.end()){
		return mp[to_string(num)];
	}

	return mp[to_string(num)] = getNum(num/P) + getNum(num/Q);
}