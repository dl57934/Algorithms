#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int n, alldistance;
vector<pair<int,int> > road[10002];

void input(){
	
	int start, destination, cost;
	scanf("%d", &n);

	for(int i = 1; i < n; i++){
		scanf("%d %d %d", &start, &destination, &cost);
		road[start].push_back(make_pair(destination, cost));
		road[destination].push_back(make_pair(start, cost));
	}
}

int bfs(int start){
	int check[10002] = {0, };
	int vertex[10002] = {0, };
	vertex[start] = 0;
	queue<pair<int, int> > qu;
	qu.push(make_pair(start, 0));

	while(!qu.empty()){
		pair<int, int> now = qu.front();
		int nowPoint = now.first;
		int nowCost = now.second;
		check[nowPoint] = 1;
		qu.pop();
		for(auto next : road[nowPoint]){
			int nextPoint = next.first;
			int nextCost = next.second;
			if(!check[nextPoint]){
				qu.push(make_pair(nextPoint, nowCost + nextCost));
				check[nextPoint] = 1;
				vertex[nextPoint] = nowCost + nextCost;
			}
		}
	}
	int index = 0, maxDistance = 0;
	for(int i = 1; i <= n; i++){
		if(maxDistance < vertex[i]){
			maxDistance = vertex[i];
			index = i;
		}
	}
	alldistance = maxDistance;
	return index;
}

int main(){
	input();
	int startIndex = bfs(1);
	bfs(startIndex);
	printf("%d", alldistance);
}