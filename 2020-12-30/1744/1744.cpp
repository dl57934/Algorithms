#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
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

vector<pair<ll, ll> > point;
vector<pair<double, pair<ll, ll> > > weight;

int main(){	
	int N, M;
	ll x, y;
	Disjoint disjoint;
	scanf("%d %d", &N, &M);

	disjoint.set(N);

	for(int i = 0; i < N; i++){
		scanf("%lld %lld", &x, &y);
		point.push_back(make_pair(x, y));
	}

	for(int i = 0; i< M; i++){
		scanf("%lld %lld", &x, &y);
		disjoint.merge(x, y);
	}

	for(int base = 1; base <= N; base++){
		for(int comp = base+1; comp <= N; comp++){
			if(disjoint.find(base) == disjoint.find(comp))
				continue;
			double distance = sqrt(pow(abs(point[base-1].first - point[comp-1].first), 2) + pow(abs(point[base-1].second - point[comp-1].second), 2));
			weight.push_back(make_pair(distance,make_pair(base, comp)));
		}
	}

	sort(weight.begin(), weight.end());

	double result = 0.0;
	for(auto edge : weight){
		double cost = edge.first;
		pair<ll, ll> now = edge.second;
		ll start = now.first;
		ll end = now.second;

		if(disjoint.find(start) == disjoint.find(end))
			continue;

		disjoint.merge(start, end);

		result+=cost;
	}

	printf("%.2lf", result);
}