#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <pair<int ,int> > map[100002];
long long maxDistance[100002];
queue <int> qu;
int V;


void input();
int bfs(int startPoint);

int main(){
	input();
	
	int nextPoint = bfs(1);
	bfs(nextPoint);
	printf("%lld", maxDistance[nextPoint]);
}

void input(){
	scanf("%d", &V);
	int vertex, end, weight;
	for(int i = 0; i < V; i++){
		scanf("%d", &vertex);
		for(;;){
			scanf("%d", &end);
			if(end == -1)
				break;
			else{
				scanf("%d", &weight);
				map[vertex].push_back(make_pair(end, weight));
			}
		}
	}
}

int bfs(int startPoint){
	long long distance[100002] = {0 ,};
	int visited[100002] = {0, };
	qu.push(startPoint);
	int max = 0;
	int maxPoint = 0;
	while(!qu.empty()){
		int nowPoint = qu.front();
		qu.pop();
		visited[nowPoint] = 1;
		for(int i = 0; i < map[nowPoint].size(); i++){
			pair<int, int> next = map[nowPoint][i];
			int nextPoint = next.first;
			int nextWeight = next.second;
			if(!visited[nextPoint] && distance[nextPoint] < distance[nowPoint] + nextWeight){
				distance[nextPoint] = distance[nowPoint] + nextWeight;
				qu.push(nextPoint);
				if(max < distance[nextPoint]){
					max = distance[nextPoint];
					maxPoint = nextPoint;
				}
			}
		}
	}
	maxDistance[startPoint] = *max_element(distance, distance+V+1);
	return maxPoint;
}