#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int map[802][802];
int path[802][802];
int INF = 987654321;

void input();
void floyd();
void printPath(int start, int path);

int main(){
	input();
	floyd();

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			printf("start %d ", y);
			printPath(y, x);
			printf(" end %d\n", x);
		}
	}
}

void input(){
	scanf("%d", &N);
	scanf("%d", &M);
	int startCity, endCity, weight;
	for(int i = 1; i <= M; i++){
		scanf("%d %d %d", &startCity, &endCity, &weight);
		if(!map[startCity][endCity])
			map[startCity][endCity] = weight;
		else
			map[startCity][endCity] = min(map[startCity][endCity], weight);
	}
	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= N; x++){
			if(map[y][x] == 0)
				map[y][x] = INF;
			path[y][x] = INF;
		}
}

void floyd(){
	for(int mid = 1; mid <= N; mid++){ 
		for(int start = 1; start <= N; start++){
			for(int end = 1; end <= N; end++){
				if(start == end)
					map[start][end] = 0;
				else if(map[start][end] > map[start][mid] + map[mid][end]) {					
					map[start][end] = map[start][mid] + map[mid][end];
					path[start][end] = mid;
				}
			}
		}
	}
}

void printPath(int start, int end){
	if(path[start][end] == INF)
		return;
	printPath(start, path[start][end]);
	printf("%d ", path[start][end]);
	printPath(path[start][end], end);
}