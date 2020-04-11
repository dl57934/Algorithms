#include <cstdio>
#include <algorithm>

using namespace std;

int INF = 987654321;
int n, m;
int map[102][102];

void input();
void floyd();

int main(){
	input();
	floyd();
	for(int i = 1; i <= n; i++){
		for(int y = 1; y <= n; y++){
			if(map[i][y] == INF)
				printf("0 ");
			else
			printf("%d ", map[i][y]);

		}
		printf("\n");
	}
}

void input(){
	int a, b, c;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(map[a][b] == 0){
			map[a][b] = c;
		}
		else{
			map[a][b] = min(map[a][b], c);
		}
	}

	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			if(map[y][x] == 0)
				map[y][x] = INF;
		}
	}
}

void floyd(){
	for(int mid = 1; mid <= n; mid++){
		for(int start = 1; start <= n; start++){
			for(int end = 1; end <= n; end++){
				if(start != end)
				map[start][end] = min(map[start][mid] + map[mid][end], map[start][end]);
			}
		}
	}
}