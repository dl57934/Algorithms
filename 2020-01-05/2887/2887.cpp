#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define ll long long 
#define element pair<ll, pair<ll, ll> >

vector<pair<ll, ll> > vcX, vcY, vcZ;
vector<element> weights;

typedef struct DisjointSet{
	ll parent[100002];

	void set(int N){
		for(int i = 1; i <= N; i++){ 
			parent[i] = i;
		}
	}

	int find(ll a){
		if(a == parent[a])
			return a;
		return parent[a] = find(parent[a]);
	}

	void merge(int a, int b){
		a = find(a), b = find(b);

		if(a == b)
			return ;

		parent[a] = b;
	}
}DisjointSet;



int main(){
	ll N, x, y, z;
	scanf("%lld", &N);

	DisjointSet disjoint;
	disjoint.set(N);
	for(int i = 1; i <= N; i++){
		scanf("%lld %lld %lld", &x, &y, &z);
		vcX.push_back(make_pair(x, i));
		vcY.push_back(make_pair(y, i));
		vcZ.push_back(make_pair(z, i));
	}

	sort(vcX.begin(), vcX.end());
	sort(vcY.begin(), vcY.end());
	sort(vcZ.begin(), vcZ.end());

	for(int i = 1; i < N; i++){
		pair<ll, ll> nowX = vcX[i], previousX = vcX[i - 1];
		pair<ll, ll> nowY = vcY[i], previousY = vcY[i - 1];
		pair<ll, ll> nowZ = vcZ[i], previousZ = vcZ[i - 1];
		
		weights.push_back(make_pair(abs(nowX.first - previousX.first), make_pair(nowX.second, previousX.second)));
		weights.push_back(make_pair(abs(nowY.first - previousY.first), make_pair(nowY.second, previousY.second)));
		weights.push_back(make_pair(abs(nowZ.first - previousZ.first), make_pair(nowZ.second, previousZ.second)));
	}

	sort(weights.begin(), weights.end());

	ll result = 0;

	for(auto line : weights){
		ll cost = line.first;
		ll point1 = line.second.first, point2 = line.second.second; 

		if(disjoint.find(point1) == disjoint.find(point2))
			continue;
		disjoint.merge(point1, point2);

		result+=cost;
	}

	printf("%lld", result);
}