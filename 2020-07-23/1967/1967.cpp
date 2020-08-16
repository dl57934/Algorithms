#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<pair<int, int> > road[10002];
int allDistance;
void input();
int bfs(int start);

int main(){
	input();
	int nextPoint = bfs(1);
	bfs(nextPoint);
	printf("%d", allDistance);
}

void input(){
	int start, destination, cost;
	scanf("%d", &N);
	for(int i = 1; i < N; i++){
		scanf("%d %d %d", &start, &destination, &cost);
		road[start].push_back(make_pair(destination, cost));
		road[destination].push_back(make_pair(start, cost));
	}
}

int bfs(int start){
	int vertex[10002] = {0, };
	int check[10002] = {0, };
	queue<pair<int, int> > qu;
	qu.push(make_pair(start, 0)); // vertex, cost;

	while(!qu.empty()){
		pair<int, int> now = qu.front();
		int nowPoint = now.first;
		int nowCost = now.second;
		qu.pop();
		check[nowPoint] = 1;
		for(auto next:road[nowPoint]){
			int nextPoint = next.first;
			int nextCost = next.second;
			if(check[nextPoint] == 0){
				vertex[nextPoint] = nowCost + nextCost;
				qu.push(make_pair(nextPoint, vertex[nextPoint]));
			}
		}
	}

	int maxDistnace = 0;
	int maxIndex = 0;
	for(int i = 1; i <= N; i++){
		if(maxDistnace < vertex[i]){
			maxDistnace = vertex[i];
			maxIndex = i;
		}
	}

	allDistance=maxDistnace;
	return maxIndex;
}