#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int map[802][802];
int INF = 987654321;

void input();
void floyd();

int main(){
	input();
	floyd();

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			if(map[y][x] == INF)
				printf("0 ");
			else
				printf("%d ", map[y][x]);
		}
		printf("\n");
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
		for(int x = 1; x <= N; x++)
			if(map[y][x] == 0)
				map[y][x] = INF;
}

void floyd(){
	for(int mid = 1; mid <= N; mid++){ 
		for(int start = 1; start <= N; start++){
			for(int end = 1; end <= N; end++){
				if(start == end)
					map[start][end] = 0;
				else
					map[start][end] = min(map[start][end], map[start][mid] + map[mid][end]);
			}
		}
	}
}