#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Disjoint{
	int parent[1002];
	void set(int N){
		for(int i = 1; i <= N; i++)
			parent[i] = i;
	}

	int find(int a){
		if(parent[a] == a)
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

int main(){
	int N, M;
	long long result = 0;
	vector<pair<int, pair<int, int> > > vc;
	Disjoint disjoint;
	scanf("%d %d", &N, &M);
	disjoint.set(N);
	int start, end, cost;
	
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &start, &end, &cost);
		vc.push_back(make_pair(cost, make_pair(start, end)));
	}

	sort(vc.begin(), vc.end());
	
	for(auto edge: vc){
		int cost = edge.first;
		int a = edge.second.first, b = edge.second.second;
	
		if(disjoint.find(a) == disjoint.find(b)) continue;

		disjoint.merge(a, b);
		result += cost;
	}

	printf("%lld", result);
}