#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define point pair<int, pair<int, int> >
using namespace std;
int N, M, K;
vector<point> edge[102];
const int INF = 98765432;
void input();
void dajickStra();

int main(){
	int testCase;
	scanf("%d", &testCase);

	for(int cs = 0; cs < testCase; cs++){
		input();
		dajickStra();
	}
}

void input(){
	scanf("%d %d %d", &N, &M, &K);
	int u, v, c, d;
	for(int i = 1; i <= N; i++)
		edge[i].clear();

	for(int i = 0; i < K; i++){
		scanf("%d %d %d %d", &u, &v, &c, &d);
		edge[u].push_back(make_pair(d, make_pair(c, v))); // distance cost, point
	}
}

void dajickStra(){
	priority_queue<point, vector<point>, greater<point> > pq; // distance cost point 
	int vertex[102][10002] = {0, };

	for(int i = 1; i <= N; i++){
		for(int money = 0; money <= 10000; money++)
			vertex[i][money] = INF;
	}

	pq.push(make_pair(0, make_pair(0, 1)));

	while(!pq.empty()){
		point now = pq.top();
		int nowWeight = now.first;
		int nowCost = now.second.first;
		int nowPoint = now.second.second;
		pq.pop();
		for(auto next : edge[nowPoint]){
			int nextWeight = next.first;
			int nextCost = next.second.first;
			int nextPoint = next.second.second;
			if(nextCost + nowCost == M && nextPoint != N)
				continue;
			if(vertex[nextPoint][nowCost + nextCost] > nextWeight + nowWeight && nowCost + nextCost <= M){	
				vertex[nextPoint][nowCost + nextCost] = nextWeight + nowWeight;
				pq.push(make_pair(nextWeight + nowWeight, make_pair(nowCost + nextCost, nextPoint)));
			}
		}
	}
	int minValue = *min_element(vertex[N], vertex[N]+M+1);

	if(minValue == INF)
		printf("Poor KCM\n");
	else
		printf("%d\n", minValue);
}