#include <cstdio>
#include <vector>

using namespace std;

vector<int> vertex[200002];

int v1, v2;
int countNum;
void dfs(int vert, int visited[]);

int main(){
	int N, Q;
	
	scanf("%d %d", &N, &Q);
	
	for(int i = 0; i < N; i++){
		scanf("%d %d", &v1, &v2);
		vertex[v1].push_back(v2);
		vertex[v2].push_back(v1);
	}

	for(int i = 0; i < Q; i++){	
		int visited[200002] = {0, };
		countNum = 0;
		scanf("%d %d", &v1, &v2);
		dfs(v1, visited);
		printf("%d\n", countNum);
	}
}

void dfs(int vert, int visited[]){
	if(vert == v2){
		countNum++;
		return ;
	}

	visited[vert] = 1;

	for(auto next : vertex[vert]){
		if(visited[next] == 0){
			dfs(next, visited);
		}
	}

}