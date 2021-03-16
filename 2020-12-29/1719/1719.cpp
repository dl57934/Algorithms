#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
int n, m;
int map[202][202], result[202][202];

int main(){
	scanf("%d %d", &n, &m);

	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			map[y][x] = 987654321;
		}
	}

	int y, x, cost;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &y, &x, &cost);
		map[y][x] = cost;
		map[x][y] = cost;
	}


	for(int mid = 1; mid <= n; mid++){
		for(int x = 1; x <= n; x++){
			for(int y = 1; y <= n; y++){
				if(x != y && map[x][y] > map[x][mid] + map[mid][y]){
					map[x][y] = min(map[x][y], map[x][mid] + map[mid][y]);
					
					result[x][y] = result[x][mid]!= 0 ? result[x][mid] : mid;
				}
			}
		}
	}


	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= n; x++){
			if(y == x)
				printf("- ");
			else if(result[y][x] == 0){
				printf("%d ", x);
			}
			else
				printf("%d ", result[y][x]);
		}
		printf("\n");
	}
}