#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define point pair<int, pair<int, int> >
using namespace std;

int N, M, K;
vector<point> road[102]; // 거리, 비용, 도착지 순서
int vertex[102][10002];
int INF = 987654321;
void init();
void input();
void dajickstra();

int main(){
	int testCase;
	scanf("%d", &testCase);

	for(int cs = 0; cs < testCase; cs++){
		init();
		input();
		dajickstra();
		int result = *min_element(vertex[N], vertex[N] + 10001);
		if(result == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", result);
	}
}

void init(){
	for(int i = 0; i <= 100; i++){
		for(int money = 0; money <= 10000; money++){
			vertex[i][money] = INF;
 		}
	}

	for(int i = 1; i <= 100; i++)
		road[i].clear();
}

void input(){
	int u, v, c, d;
	scanf("%d %d %d", &N, &M, &K);

	for(int ticket = 0; ticket < K; ticket++){
		scanf("%d %d %d %d", &u, &v, &c, &d);
		road[u].push_back(make_pair(d, make_pair(c, v)));
	}
}

void dajickstra(){
	priority_queue <point, vector<point>, greater<point> >pq; // 거리, 비용, 지점
	pq.push(make_pair(0, make_pair(0, 1)));

	while(!pq.empty()){
		int nowWeight = pq.top().first;
		int nowCost = pq.top().second.first;
		int nowPoint = pq.top().second.second;
		pq.pop();
		

		for(auto next : road[nowPoint]){
			int nextWeight = next.first;
			int nextCost = next.second.first;
			int nextPoint = next.second.second;

			if(nowCost + nextCost == M && nextPoint!=N)
				continue;

			if(vertex[nextPoint][nowCost + nextCost] > nowWeight+nextWeight && nowCost + nextCost <= M){
				vertex[nextPoint][nowCost + nextCost] = nowWeight+nextWeight;
				pq.push(make_pair(nowWeight+nextWeight, make_pair(nowCost + nextCost, nextPoint)));
			}
		}
	}
}

