#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <pair<int, int> > map[100002];
queue <int> qu;

int visited[100002];
int maxDistance;
int maxIndex;
void input();
int bfs(int index);
void dfs(int index, int cost);


int main(){
	input();
	// bfs(bfs(1));
	dfs(1, 0);

	for(int i = 1; i <= N; i++)
		visited[i] = 0;
	maxDistance = 0;

	dfs(maxIndex, 0);
	printf("%d", maxDistance);
}

void input(){
	int starter, end, distance; 
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &starter);
		for(;;){
			scanf("%d", &end);
			if(end==-1)
				break;
			
			scanf("%d", &distance);
			
			map[starter].push_back(make_pair(end, distance));
			map[end].push_back(make_pair(starter, distance));
		}
	}
}

void dfs(int index, int cost){
	if(visited[index] != 0)
		return ;

	if(maxDistance < cost){
			maxDistance = cost;
			maxIndex = index;
	}

	visited[index] = 1;

	for(int i = 0; i < map[index].size(); i++){
		pair<int, int> next = map[index][i];
		int nextIndex = next.first;
		int nextWeight = next.second;
		dfs(nextIndex, nextWeight + cost);
	} 
}

int bfs(int index){
	qu.push(index);
	int result[100002] = {0, };
	int maxPoint = 0;
	int max = 0;
	while(!qu.empty()){
		int starter = qu.front();
		qu.pop();
		for(int i = 0; i < map[starter].size(); i++){
			pair<int, int> next = map[starter][i];
			int nextPoint = next.first;
			int distance = next.second;
			if(result[nextPoint] < distance + result[starter]){
				result[nextPoint] = distance + result[starter];
				qu.push(nextPoint);
				if(max < result[nextPoint]){
					maxPoint = nextPoint;
					max = result[nextPoint];
				}
			}
		}
	}

	maxDistance = *max_element(result, result+N+1);
	return maxPoint;
}