#include <cstdio>
#include <algorithm>

int INF = 987654321;

int map[404][404];
int V, E;

int minVal = INF;

void input();
void floyd();

using namespace std;

int main(){
	input();
	floyd();
	for(int i = 1; i <= V; i++){
		for(int x = 1; x <= V; x++){
			if(i != x){
				minVal = min(minVal, map[i][x] + map[x][i]);
			}
		}
	}
	if( minVal == INF){
		printf("-1");
	}else
		printf("%d", minVal);
}

void input(){
	scanf("%d %d", &V, &E);
	int start, end, weight;
	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &start, &end, &weight);
		if(map[start][end])
			map[start][end] = min(map[start][end], weight);
		else
			map[start][end] = weight;
	}

	for(int y = 1; y <= V; y++)
		for(int x = 1; x <= V; x++)
			if(map[y][x] == 0)
				map[y][x] = INF;
}

void floyd(){
	for(int mid = 1; mid <= V; mid++){
		for(int start = 1; start <= V; start++){
			for(int end = 1; end <= V; end++){
				if(start == end)
					map[start][end] = 0;
				else {
					map[start][end] = min(map[start][end], map[start][mid] + map[mid][end]);
				}
			}
		}
	}
}