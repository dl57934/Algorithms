#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define  point pair<int, int> 
using namespace std;
const int INF = 98765432;
int V, E, start;
vector<point> edge[20002];
int vertex[20002];
void input();
void dajickStra();

int main(){
	input();
	dajickStra();

	for(int i = 1; i <= V; i++){
		if(vertex[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", vertex[i]);
	}
}

void input(){
	int u, v, w;
	scanf("%d %d %d", &V, &E, &start);
	for(int i = 1; i <= V; i++)
		vertex[i] = INF;
	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &u, &v, &w);
		edge[u].push_back(make_pair(w, v));
	}
}

void dajickStra(){
	priority_queue<point, vector<point>, greater<point> > pq; 
	int check[20002] = {0, };
	vertex[start] = 0;
	pq.push(make_pair(0, start)); // 시작점, distance;

	while(!pq.empty()){
		pair<int, int> now = pq.top();
		int nowWeight = now.first;
		int nowPoint = now.second;
		pq.pop();
		if(check[nowPoint])
			continue;
		check[nowPoint] = 1;

		for(auto next : edge[nowPoint]){
			int nextPoint = next.second;
			int nextWeight = next.first;
			if(vertex[nextPoint] > vertex[nowPoint] + nextWeight){
				vertex[nextPoint] = vertex[nowPoint] + nextWeight;
				pq.push(make_pair(vertex[nextPoint], nextPoint));
			}			
		}
	}
}