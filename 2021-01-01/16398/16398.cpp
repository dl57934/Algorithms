#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

typedef struct Disjoint{
	int parent[1002];

	void set(int N){
		for(int i = 1; i <= N; i++)
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
			return ;

		parent[a] = b;
	}
}Disjoint;

vector<pair<ll, pair<ll, ll> > > vc;
ll result = 0;

int main(){
	int N;
	ll cost;
	scanf("%d", &N);
	Disjoint disjoint;
	disjoint.set(N);
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			scanf("%lld", &cost);
			if(y < x){
				vc.push_back(make_pair(cost, make_pair(y, x)));
			}
		}
	}

	sort(vc.begin(), vc.end());

	for(auto now : vc){
		ll cost = now.first;
		ll start = now.second.first, end = now.second.second;

		if(disjoint.find(start) == disjoint.find(end)){
			continue;
		}

		disjoint.merge(start, end);
		result+= cost;
	}

	printf("%lld", result);
}