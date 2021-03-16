#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long


typedef struct Disjoint{
	int parent[100002];

	void set(int V){
		for(int i = 1; i <= V; i++)
			parent[i] = i;
	}

	int find(int a){
		if(a == parent[a])
			return a;

		return parent[a] = find(parent[a]);
	}

	void merge(int a, int b){
		a = find(a), b = find(b);

		if(a == b)
			return;

		parent[a] = b;
	}
}Disjoint;

int N, M;
vector<pair<ll, pair<ll, ll> > > vc;

int main(){
	Disjoint disjoint;
	ll a, b, c, result = 0;
	scanf("%d %d", &N, &M);
	disjoint.set(N);

	for(int i = 0; i < M; i++){
		scanf("%lld %lld %lld", &a, &b, &c);
		vc.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(vc.begin(), vc.end());
	ll lastNum  = 0;
	
	for(auto now : vc){
		ll cost = now.first;

		if(disjoint.find(now.second.first) == disjoint.find(now.second.second))
			continue;
		disjoint.merge(now.second.first, now.second.second);
		lastNum = cost;
		result += cost;
	}

	printf("%lld", result - lastNum);
}