#include <cstdio>
#include <vector>
#include <queue>
#define point pair<int, int>
using namespace std;

int INF = 98765432;
int K, V, E;
int vertex[20002], check[20002];
vector<point> line[20002];

void dajickstra();
void init();

int main(){
	scanf("%d %d %d", &V, &E, &K);
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
	for(int i = 1; i <= V; i++)
		vertex[i] = INF;
	int u, v, w;
	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &u, &v, &w);
		line[u].push_back(make_pair(w, v));
	}
}

void dajickstra(){
	priority_queue <point, vector<point>, greater<point> > pq;
	pq.push(make_pair(0, K));
	vertex[K] = 0;

	while(!pq.empty()){
		point now = pq.top();
		pq.pop();
		if(check[now.second]) continue;
		check[now.second] = 1;
		for(auto next : line[now.second]){
			if(vertex[next.second] > now.first + next.first){
				vertex[next.second] = now.first + next.first;
				pq.push(make_pair(vertex[next.second], next.second));
			}
		}
	}
}