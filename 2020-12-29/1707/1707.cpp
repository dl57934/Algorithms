#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

void solve();

int main(){
	int K;
	scanf("%d", &K);

	for(int i = 0; i < K; i++)
		solve();
}

void solve(){
	int vertex[20002] = {0, }, visited[20002] = {0, }, group[20002] = {0, };
	int V, E, v1, v2;
	queue<pair<int, int> > qu;
	vector<int> vc[20002];

	scanf("%d %d", &V, &E);

	for(int i = 0; i < E; i++){
		scanf("%d %d", &v1, &v2);
		vc[v1].push_back(v2);
		vc[v2].push_back(v1);
	}

	for(int i = 1; i <= V; i++ ){
		if(visited[i] == 0){
			qu.push(make_pair(i, -1));
			while(!qu.empty()){
				int now = qu.front().first;
				int nowGroup = qu.front().second;
				qu.pop();
				group[now] = nowGroup;
				visited[now] = 1;
				for(auto next : vc[now]){
					if(visited[next] && nowGroup == group[next]){
						printf("NO\n");
						return ;
					}else if(visited[next] == 0){
						qu.push(make_pair(next, nowGroup == -1 ? 1 : -1));
					}
				}
			}	
		}
	}

	printf("YES\n");
}