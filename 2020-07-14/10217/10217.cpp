#include <cstdio>
#include <algorithm>
#include <queue>
#define point pair<int, pair<int, int> > // distance, cost, point
using namespace std;

void init();
void input();
void dajickstra();

int N, M, K;
int INF = 987654321;
int vertex[102][10002];
vector <point> map[102];

int main(){
	int testCase;
	scanf("%d", &testCase);

	for(int cs = 0; cs < testCase; cs++){
		int result = INF;
		init();
		input();
		dajickstra();
		for(int money = 1; money <= M; money++){
			if(result > vertex[N][money]){
				result = vertex[N][money];
			}
		}

		if(result == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", result);
	}
}

void init(){
	for(int i = 2; i <= 100; i++)
		for(int money = 1; money <= 10000; money++)
			vertex[i][money] = INF;

	for(int y = 1; y <= 100; y++){
		map[y].clear();
	}
			
}

void input(){
	int u, v, c, d;
	scanf("%d %d %d", &N, &M, &K);

	for(int i = 0; i < K; i++){
		scanf("%d %d %d %d", &u, &v, &c, &d);
		map[u].push_back(make_pair(v, make_pair(d, c)));
	}
}


void dajickstra(){
	int check[102] = {0, };
	priority_queue <point, vector<point>, greater<point> >pq;
	pq.push(make_pair(0, make_pair(0, 1)));
	while(!pq.empty()){
		point now = pq.top();
		int nowDistance = now.first;
		int nowCost = now.second.first;
		int nowPoint = now.second.second;

		pq.pop();
		if(check[nowPoint])
			continue;
		check[nowPoint] = 1;
		
		for(auto next : map[nowPoint]){
			int nextPoint = next.first;
			int nextDistance = next.second.first;
			int nextCost = next.second.second;

			if(nextPoint != N && nowCost + nextCost == M)
				continue;

			if(vertex[nextPoint][nowCost + nextCost] > nextDistance + nowDistance && M >= nowCost + nextCost){
				vertex[nextPoint][nowCost + nextCost] = nextDistance + nowDistance;
				pq.push(make_pair(nextDistance + nowDistance, make_pair(nowCost + nextCost, nextPoint)));
			}
		}
	}
}




