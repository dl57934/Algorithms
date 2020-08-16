#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> line[100002];
int vertex[100002], check[100002];

void bfs();

int main(){
	int N, point1, point2;

	scanf("%d", &N);

	for(int i = 1; i < N; i++){	
		scanf("%d %d", &point1, &point2);

		line[point1].push_back(point2);
		line[point2].push_back(point1);
	}

	bfs();

	for(int i = 2; i <= N; i++)
		printf("%d\n", vertex[i]);
}

void bfs(){
	queue<int> qu;
	qu.push(1);

	while(!qu.empty()){
		int parent = qu.front();
		qu.pop();
		if(check[parent]) continue;
		check[parent] = 1;

		for(int next : line[parent]){
			if(check[next] == 0){
				vertex[next] = parent;
				qu.push(next);
			}
		}
	}
}