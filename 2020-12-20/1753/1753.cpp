#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define INF 987654321
#define element pair<int, int> 

priority_queue<element, vector<element>, greater<element> > pq;
vector <pair<int, int> >point[20002];
int vertex[20002], visited[20002];
int V, E, startPoint;

void init();
void dajickstra();

int main(){
	scanf("%d %d %d", &V, &E, &startPoint);
	init();
	dajickstra();

	for(int i = 1; i <= V; i++){
		if(vertex[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", vertex[i]);
	}
}

void init(){
	for(int i = 1; i <= 20000; i++)
		vertex[i] = INF;

	vertex[startPoint] = 0;
	int u, v ,e;

	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &u, &v, &e);
		point[u].push_back(make_pair(v, e));
	}

	pq.push(make_pair(0, startPoint));
}

void dajickstra(){
	while(!pq.empty()){
		pair<int, int> now = pq.top();
		int nowDistance = now.first, nowPoint = now.second;
		pq.pop();
		visited[nowPoint] = 1;
		for(auto next : point[nowPoint]){
			int nextPoint = next.first;
			int nextWeight = next.second;
			if(vertex[nextPoint] > nextWeight + nowDistance && visited[nextPoint] == 0){
				vertex[nextPoint] = nextWeight + nowDistance;
				pq.push(make_pair(vertex[nextPoint], nextPoint));
			}
		}
	}
}