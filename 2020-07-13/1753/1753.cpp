#include <cstdio>
#include <queue>
#include <vector>
#define point pair<int,int>
using namespace std;

priority_queue <point, vector<point >, greater<point> > pq;
vector<point> map[20002];
int vertex[20002];
int check[20002];

int V, E;

void input();
void dajickStra();

int main(){
	input();
	dajickStra();
	for(int i = 1; i <= V; i++){
		if(vertex[i] == 98765432)
			printf("INF\n");
		else
			printf("%d\n", vertex[i]);
	}
}

void input(){
	int INF = 98765432;
	int startPoint, u, v, w;
	scanf("%d %d %d", &V, &E, &startPoint);
	
	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &u, &v, &w);
		map[u].push_back(make_pair(v, w));
	}

	for(int vert = 1; vert <= V; vert++)
		vertex[vert] = INF;
	pq.push(make_pair(0, startPoint));
	vertex[startPoint] = 0;
}

void dajickStra(){
	while(!pq.empty()){
		point  now = pq.top();
		int distance = now.first;
		int nowPoint = now.second;
		pq.pop();
		check[nowPoint] = 1;
		for(auto next : map[nowPoint]){
			int nextPoint = next.first;
			int nextDistance = next.second;
			if(check[nextPoint] == 0){
				if(distance + nextDistance < vertex[nextPoint]){
					vertex[nextPoint] = distance + nextDistance;
					pq.push(make_pair(vertex[nextPoint], nextPoint));
				}
			}
		}
	}
}