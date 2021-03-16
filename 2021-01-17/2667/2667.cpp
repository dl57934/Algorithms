#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int map[27][27];
int N, complexHome;
vector<int> result;
int ypos[4] = {0, 1, 0, -1}, xpos[4] = {1, 0, -1, 0};

void dfs(int y, int x);

int main(){
	scanf("%d", &N);
	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= N; x++)
			scanf("%1d", &map[y][x]);

	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= N; x++)
			if(map[y][x] == 1){
				complexHome = 1;
				dfs(y, x);
				result.push_back(complexHome);
			}

	printf("%d\n", result.size());
	sort(result.begin(), result.end());

	for(int homeCount : result)
		printf("%d\n", homeCount);
}

void dfs(int y, int x){
	map[y][x] = 0;

	for(int i = 0; i < 4; i++){
		int nextY = y + ypos[i];
		int nextX = x + xpos[i];
		if(map[nextY][nextX]){
			complexHome++;
			dfs(nextY, nextX);
		}
	}
}