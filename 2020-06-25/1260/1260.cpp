#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> qu;
vector<int> map[1002];
int checkDFS[1002];
int checkBFS[1002];

void dfs(int point);
void bfs(int point);
void input();

int main(){
	input();
}

void dfs(int point){
	checkDFS[point] = 1;
	printf("%d ", point);
	for(int nextPoint : map[point]){
		if(checkDFS[nextPoint] == 0){
			dfs(nextPoint);
		}
	}
}

void bfs(int point){
	qu.push(point);
	checkBFS[point] = 1;
	while(!qu.empty()){
		int visitPoint = qu.front();
		qu.pop();
		
		printf("%d ", visitPoint);
		for(int nextPoint : map[visitPoint]){
			if(checkBFS[nextPoint] == 0){
				checkBFS[nextPoint] = 1;
				qu.push(nextPoint);
			}
		}
	}

}

void input(){
	int N, M, V;
	int pt1, pt2;
	scanf("%d %d %d", &N, &M, &V);

	for(int i = 0; i < M; i++){
		scanf("%d %d", &pt1, &pt2);
		map[pt1].push_back(pt2);
		map[pt2].push_back(pt1);
	}

	for(int i = 1; i <= N; i++)
		sort(map[i].begin(),map[i].end());

	dfs(V);
	printf("\n");
	bfs(V);
}