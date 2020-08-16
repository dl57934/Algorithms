#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> road[100002];
int vertex[100002], check[100002];

void bfs();

int main(){
	int N, start, end;
	scanf("%d", &N);

	for(int i = 2; i <= N; i++){
		scanf("%d %d", &start, &end);
		road[start].push_back(end);
		road[end].push_back(start);
	}
	bfs();

	for(int i = 2; i <= N; i++)
		printf("%d\n", vertex[i]);
}

void bfs(){
	queue <int> qu;
	qu.push(1);

	while(!qu.empty()){
		int now = qu.front();
		qu.pop();
		check[now] = 1;
		for(auto next : road[now]){
			if(check[next] == 0){
				vertex[next] = now;
				qu.push(next);
			}
		}
	}
}