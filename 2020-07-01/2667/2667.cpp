#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int home;
int xPos[4] = {0, 1, 0, -1};
int yPos[4] = {1, 0, -1, 0};
int map[27][27];
vector<int> result;

void input();
void dfs(int y, int x);

int main(){
	input();

	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= N; x++)
			if(map[y][x]){
				dfs(y, x);
				result.push_back(home);
				home = 0;
			}
	
	printf("%d\n", result.size());

	sort(result.begin(), result.end());

	for(auto re: result){
		printf("%d\n", re);
	}
}

void input(){
	scanf("%d", &N);
	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= N; x++)
			scanf("%1d", &map[y][x]);
}

void dfs(int y, int x){
	map[y][x] = 0;
	home++;
	for(int pos = 0; pos < 4; pos++){
		int ny = y + yPos[pos];
		int nx = x + xPos[pos];
		if(ny >= 1 && ny <=N && nx >= 1 && nx <= N && map[ny][nx]){
			dfs(ny, nx);
		}
	}
}