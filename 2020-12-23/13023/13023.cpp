#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> friendShip[2002];
int value[2002];
void dfs(int val, int size, int visited[]);
int N, M, a, b;

int main(){
	
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++){
		scanf("%d %d", &a, &b);
		friendShip[a].push_back(b);
		friendShip[b].push_back(a);
	}

	for(int i = 0; i < N; i++){
		int visited[2002] = {0, };
		dfs(i, 0, visited);	
	}
	
	printf("1");
}

void dfs(int val, int size, int visited[]){
	visited[val] = 1;
	value[size] = val;
	if(size == 4){
		printf("1");
		exit(0);
	}

	for(auto next : friendShip[val]){
		if(visited[next] == 0){
			dfs(next, size+1, visited);
			visited[next] = 0;
		}	
	}

}