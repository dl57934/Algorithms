#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int V, E;
int startPoint;
int INF = 987654321;
int distances[20002];
int visited[20002];

vector <pair<int, int> > v[20002];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qu;

void set();
void input();
void dijkstra(int start);

int main(){
	input();
	set();
	dijkstra(startPoint);
	for(int i = 1; i <= V; i++){
		if(distances[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", distances[i]);
	}
}

void input(){
	
	scanf("%d %d", &V, &E);
	scanf("%d", &startPoint);

	for(int i = 1; i <= E; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(c, b));
	}
}

void dijkstra(int start){

	while(!qu.empty()){
		pair<int, int> point = qu.top();
		qu.pop();
		int weight = point.first;
		int nowPoint = point.second;
		visited[nowPoint] = 1;
		for(int i = 0; i < v[nowPoint].size(); i++){
			int moveWeight = v[nowPoint][i].first; // weight
			int nextPoint = v[nowPoint][i].second; // nextPoint
			if(!visited[nextPoint]){
				if( distances[nextPoint] > moveWeight + weight){
					distances[nextPoint] = moveWeight + weight;
					qu.push(make_pair(distances[nextPoint], nextPoint));
				}
			}
		}
	}
	
}


void set(){
	for(int i = 1; i <=V; i++)
		distances[i] = INF;
	distances[startPoint] = 0;
	visited[startPoint] = 1;
	qu.push(make_pair(0, startPoint));
}