#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define element pair<ll, ll> 
using namespace std;

vector<pair<int, int> > pathInfo[1002];
queue<int> qu;
int N, M;
ll vertex[1002];
vector<int> ingreed[1002];

void topologySort(){
	queue <int> qu;
	vector<int> history[1002];

	for(int i = 1; i <= N; i++)
		if(ingreed[i].size() == 0)
			qu.push(i);

	vector<int> load;

	while(!qu.empty()){
		int now = qu.front();
		qu.pop();
		for(auto next : pathInfo[now]){
			ingreed[next.second].pop_back();
			if(vertex[next.second] < vertex[now] + next.first) {
				vertex[next.second] = vertex[now] + next.first;
				
				history[now].push_back(next.second);
				history[next.second] = history[now];
				history[now].pop_back();
			}

			if(ingreed[next.second].size() == 0)
				qu.push(next.second);
		}
	}

	printf("%lld\n", vertex[1]);
	printf("1 ");
	for(auto point : history[1])
		printf("%d ", point);
}


int main(){
	vector<int> result;
	int start, end, point;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &start, &end, &point);
		pathInfo[start].push_back(make_pair(point, end));
		if(end != 1)
			ingreed[end].push_back(start);
	}
	
	topologySort();

}
