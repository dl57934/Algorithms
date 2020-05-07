#include <cstdio>
#include <map>
#include <vector>
#include <stdlib.h>

#define ll long long

using namespace std;

ll gate;
ll airplane;
vector<ll> airplaneOrder;
map<ll, ll> mp;
ll answer = 0;
void merge(int s, int b);
void input();
ll find(ll u);


int main(){
	input();
	for(ll value : airplaneOrder){
		int dock = find(value);
		if(dock != 0){
			merge(dock, dock-1);
			answer+=1;
		}else{
			break;
		}
	}

	printf("%lld", answer);
}

void input(){
	scanf("%lld", &gate);
	scanf("%lld", &airplane);
	ll value;
	for(int i = 1; i <= airplane; i++){
		scanf("%lld", &value);
		airplaneOrder.push_back(value);
	}

	for(int i = 1; i <= gate; i++)
		mp[i] = i;
}


ll find(ll u){
	if(mp[u] == u)
		return u;
	
	return mp[u] = find(mp[u]);
}

void merge(int s, int b){
	s = find(s);
	b = find(b);
	mp[s] = b;
}