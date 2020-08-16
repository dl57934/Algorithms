#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> road[100002];

void input(){
	int begin, destination;
	scanf("%d", &N);

	for(int i = 1; i < N;i ++){
		scanf("%d %d", &begin, &destination);
		road[begin].push_back(destination);
		road[destination].push_back(begin);
	}
}

void bfs(){
	int parent[100002]={0, }, check[100002] = {0, };
	queue<int> qu;
	check[1] = 1;
	qu.push(1);

	while(!qu.empty()){
		int now = qu.front();
		qu.pop();
		check[now] = 1;
		for(auto next : road[now]){
			if(check[next] == 0){
				parent[next] = now;
				qu.push(next);
			}
		}
	}
	for(int i = 2; i <= N; i++)
		printf("%d\n", parent[i]);
}

int main(){
	input();
	bfs();
}