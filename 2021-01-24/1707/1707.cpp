#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void solve();

int main(){
	int K;

	scanf("%d", &K);

	for(int i = 0; i < K; i++){
		solve();
	}
}

void solve(){
	vector<int> edge[20002];
	queue <pair<int, int> > qu;
	int visited[20002] = { 0, }, group[20002] = {0, };
	int V, E, start, end;

	scanf("%d %d", &V, &E);
	
	for(int i = 0; i < E; i++){
		scanf("%d %d", &start, &end);
		edge[start].push_back(end);
		edge[end].push_back(start);
	}

	for(int i = 0; i < V; i++){
		if(visited[i] == 0){
			qu.push(make_pair(i, 0));
			while(!qu.empty()){
				pair<int, int> now = qu.front();
				int nowVertex = now.first;
				int nowGroup = now.second;
				group[nowVertex] = nowGroup;
				visited[nowVertex] = 1;
				qu.pop();
				for(auto next : edge[nowVertex]){
					if(visited[next] == 0){
						qu.push(make_pair(next, nowGroup == 0? 1 : 0));
					}else{
						if(nowGroup == group[next]){
							printf("NO\n");
							return ;
						}
					}
				}
			}
		}
	}
	printf("YES\n");
}