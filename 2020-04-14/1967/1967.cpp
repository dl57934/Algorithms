#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector <pair<int, int> > map[10002];

int maxDistance[10002];

void input();
void bfs(int startPoint);

int main(){
	input();
	for(int i = 1; i <= N; i++)
		bfs(i);
	
	printf("%d\n", *max_element(maxDistance, maxDistance+N+1));
}

void input(){
	scanf("%d", &N);
	int start, end, weight;
	for(int i = 1; i < N; i++){
		scanf("%d %d %d", &start, &end, &weight);
		map[start].push_back(make_pair(end, weight));
		map[end].push_back(make_pair(start, weight));
	}
}

void bfs(int startPoint){
	queue <int> qu;
	qu.push(startPoint);
	int distance[10002] = {0, };
	int visited[10002] = {0, };
	while(!qu.empty()){
		int nowPoint = qu.front();
		qu.pop();
		visited[nowPoint]=1;
		for(int i = 0; i < map[nowPoint].size(); i++){
			pair<int, int> nextInfo = map[nowPoint][i];
			int nextPoint = nextInfo.first;
			int nextWeight = nextInfo.second;
			if(nextWeight+distance[nowPoint] > distance[nextPoint] && !visited[nextPoint]){
				distance[nextPoint] = nextWeight+distance[nowPoint];
				qu.push(nextPoint);
			}
		}
	}
	maxDistance[startPoint] = *max_element(distance, distance+N+1);
}