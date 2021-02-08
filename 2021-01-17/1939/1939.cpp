#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#define ll long long

using namespace std;

int N, M;
vector<pair<ll, pair<int, int> > > point;

typedef struct DisjointSet{
	int parent[100002];
	void init(int N){
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
			return;
		parent[a] = b;
	}
}DisjointSet;

int main(){
	scanf("%d %d", &N, &M);
	ll start, end, weight;
	ll distance[100002] = {0, };

	DisjointSet disjointset;
	disjointset.init(N);

	for(int i = 0; i < M; i++){
		scanf("%lld %lld %lld", &start, &end, &weight);
		point.push_back(make_pair(weight, make_pair(start, end)));
		point.push_back(make_pair(weight, make_pair(end, start)));
	}

	scanf("%d %d", &start, &end);

	sort(point.begin(), point.end(), greater<pair<ll, pair<int, int> > >());
	ll answer = 0;
	for(auto next : point){
		int now = next.second.first, destination = next.second.second;
		ll weight = next.first;

		
		if(disjointset.find(start) != disjointset.find(end)){
			disjointset.merge(now, destination);
			answer = weight;
		}
	}

	printf("%lld", answer);
}
