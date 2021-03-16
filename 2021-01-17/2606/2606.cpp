#include <cstdio>
#include <vector>

using namespace std;

vector<int> point[102];
int visit[102], virusComputer;

void dfs(int vertex);

int main(){
	int N, edges;
	int vertex1, vertex2;
	scanf("%d %d", &N, &edges);

	for(int i = 0; i < edges; i++){
		scanf("%d %d", &vertex1, &vertex2);
		point[vertex1].push_back(vertex2);
		point[vertex2].push_back(vertex1);
	}

	dfs(1);

	printf("%d", virusComputer);
}

void dfs(int vertex){
	visit[vertex] = 1;

	for(auto next : point[vertex]){
		if(visit[next] == 0){
			virusComputer++;
			dfs(next);
		}
	}
}