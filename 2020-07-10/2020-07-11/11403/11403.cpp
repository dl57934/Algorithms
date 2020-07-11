#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start);
void input();
int N;
vector<int> map[102];
int resultMap[102][102];

int main(){
	input();
	for(int i = 1; i <= N; i++)
		bfs(i);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			printf("%d ", resultMap[y][x]);
		}
		printf("\n");
	}
}

void input(){
	int value;
	scanf("%d", &N);

	for(int start = 1; start <= N; start++){
		for(int end = 1; end <= N; end++){	
			scanf("%d", &value);
			if(value == 1){
				map[start].push_back(end);
			}
		}
	}
}

void bfs(int start){
	queue <int> qu;
	int check[102] = {0,};
	qu.push(start);
	while(!qu.empty()){
		int now = qu.front();
		qu.pop();
		for(auto next : map[now]){
			if(check[next] == 0){
				check[next] = 1;
				qu.push(next);
				resultMap[start][next] = 1;
			}
		}
	}
}