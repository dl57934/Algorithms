#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int N, M, V;
int vertex[1002];
vector <int>edge[1002];


void dfs(int point){
	printf("%d ", point);
	vertex[point] = 1;

	for(auto nextPoint : edge[point]){
		if(vertex[nextPoint] == 0){
			dfs(nextPoint);
		}
	}
}

queue<int> qu;

void bfs(int point){
	qu.push(point);
	vertex[point] = 1;
	while(!qu.empty()){
		int nowPoint = qu.front(); 
		qu.pop();
		printf("%d ", nowPoint);

		for(auto nextPoint : edge[nowPoint]){
			if(vertex[nextPoint] == 0){
				vertex[nextPoint] = 1;
				qu.push(nextPoint);
			}
		}
	}
}

int main(){
	int start, end;
	scanf("%d %d %d", &N, &M, &V);

	for(int i = 0; i < M; i++){
		scanf("%d %d", &start, &end);
		edge[start].push_back(end);
		edge[end].push_back(start);
	}

	for(int i = 1; i <= N; i++)
		sort(edge[i].begin(), edge[i].end());

	dfs(V);
	printf("\n");
	memset(vertex, 0, sizeof(vertex));
	bfs(V);
}