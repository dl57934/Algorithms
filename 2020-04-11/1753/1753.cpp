#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int V, E;
int startPoint;
int INF = 987654321;
int visited[20002];
int vertex[20002];
vector <pair<int, int> > pathSaver[20002];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

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
	scanf("%d %d", &V, &E);
	scanf("%d", &startPoint);

	for(int i = 1; i <= E; i++){
		scanf("%d %d %d", &u, &v, &w);
		pathSaver[u].push_back(make_pair(w, v));
		
	}

	for(int i = 1; i <= V; i++)
		vertex[i] = INF;

	pq.push(make_pair(0, startPoint));
	vertex[startPoint] = 0;
}


void dajickStra(){
	while(!pq.empty()){
		pair<int, int> now = pq.top();
		int nowWeight = now.first;
		int nowPoint = now.second;
		pq.pop();
		visited[nowPoint] = 1;
		for(int i = 0; i < pathSaver[nowPoint].size(); i++){
			pair<int, int> next = pathSaver[nowPoint][i];
			int nextWeight = next.first;
			int nextPoint = next.second;
			if(!visited[nextPoint]){
				if(vertex[nextPoint] > nowWeight + nextWeight){
					vertex[nextPoint] = nowWeight + nextWeight;
					pq.push(make_pair(vertex[nextPoint], nextPoint));
				}
			}
		}
	}
}