#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long

int N, Q;

vector<pair<int, int> > vc[5002];

int bfs(int k, int v);

int main(){
	scanf("%d %d", &N, &Q);
	ll start, destination, weight;

	for(int i = 0; i < N-1; i++){
		scanf("%lld %lld %lld", &start, &destination, &weight);
		vc[start].push_back(make_pair(destination, weight));
		vc[destination].push_back(make_pair(start, weight));
	}
	

	ll k, v;
	for(int i = 0; i < Q; i++){
		scanf("%lld %lld", &k, &v);
		printf("%d\n",bfs(k, v));
	}
}

int bfs(int k, int v){
	int count = 0;
	queue<int> qu;
	qu.push(v);
	int visited[5002] = {0, };

	while(!qu.empty()){
		int now = qu.front();
		qu.pop();
		visited[now] = 1;
		for(auto next : vc[now]){
			if(!visited[next.first] && next.second >= k){
				count++;
				qu.push(next.first);
			}
		}
	}
			
	return count;
}