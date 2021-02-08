#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int> > > vc;

typedef struct Disjoint{
	int parent[200002];

	void set(int N){
		parent[0] = 0;
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

		if( a == b)
			return ;

		parent[a] = b;
	}
}Disjoint;

int main(){
	Disjoint disjoint;
	while(1){
		int m, n;
		
		long long result = 0, all = 0;
		int start, end, cost;
		scanf("%d %d", &m, &n);

		if(m == 0 && n == 0)
			exit(0);

		disjoint.set(m);



		for(int i = 0; i < n; i++){
			scanf("%d %d %d", &start, &end, &cost);
			all += cost;
			vc.push_back(make_pair(cost, make_pair(start, end)));
		}	

		sort(vc.begin(), vc.end());

		for(auto now : vc){
			int cost = now.first;
			int start = now.second.first, end = now.second.second;

			if(disjoint.find(start) == disjoint.find(end))
				continue;

			disjoint.merge(start, end);
			result+=cost;
		}

		printf("%lld\n", all - result);
		vc.clear();
	}
}