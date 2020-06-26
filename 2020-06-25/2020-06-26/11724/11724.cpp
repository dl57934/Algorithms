#include <cstdio>
#include <vector>

using namespace std;
int N, M;
vector <int> map[1002];
int check[1002];
void input();
void dfs(int point);

int main(){
	int count = 0;
	input();
	for(int i = 1; i <= N; i++){
		if(!check[i]){
			count += 1;
			dfs(i);
		}
	}
	printf("%d", count);
}

void input(){
	scanf("%d %d", &N, &M);
	int start, end;
	for(int order = 0; order < M; order++){
		scanf("%d %d", &start, &end);
		map[start].push_back(end);
		map[end].push_back(start);
	}
}

void dfs(int point){
	check[point] = 1;
	for(auto end : map[point]){
		if(!check[end]){
			dfs(end);
		}
	}
}