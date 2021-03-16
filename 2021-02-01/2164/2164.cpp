#include <cstdio>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

pair<int, int> map[102][102];
int xpos[4] = {0, -1, 0, 1}, ypos[4] = {1, 0, -1, 0};

int N, bridgeLength[102000], betweenLength[102][102];

int visited[102][102], bridgeVisited[102][102];

void bridgeBfs(int y, int x, int islandIndex);
void bfs(int y, int x, int islandIndex){
	
	queue<pair<int, int> > qu;
	qu.push(make_pair(y, x));
	map[y][x].second = islandIndex;
	visited[y][x] = 1;

	while(!qu.empty()){
		pair<int, int> now = qu.front();
		qu.pop();
		for(int i = 0; i < 4; i++){
			int nextY = now.first + ypos[i];
			int nextX = now.second + xpos[i];
			if(map[nextY][nextX].first == 1 && visited[nextY][nextX] == 0 && nextY >= 1 && nextX >= 1 && nextY <= N && nextX <= N){
				visited[nextY][nextX] = 1;
				map[nextY][nextX].second = islandIndex;
				qu.push(make_pair(nextY, nextX));
			}
		}
	}

}

int main(){
	scanf("%d", &N);
	memset(bridgeLength, 987654, sizeof(bridgeLength));
	memset(betweenLength, 987654, sizeof(betweenLength));
	
	int initValue = betweenLength[0][0];

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			scanf("%d", &map[y][x].first);
		}
	}

	int islandIndex = 1;
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			if(visited[y][x] == 0 && map[y][x].first == 1){
				bfs(y, x, islandIndex);
				islandIndex++;
			}
		}
	}

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			if(map[y][x].first == 1){
				memset(betweenLength, 987654, sizeof(betweenLength));

				betweenLength[y][x] = 0;
				bridgeBfs(y, x, map[y][x].second);
			}
		}
	}
	
	

	int minValue = 987654321;
	for(int i = 1; i < islandIndex; i++){
		if(minValue > bridgeLength[i])
			minValue = bridgeLength[i];
	}
	printf("%d", minValue);
}


void bridgeBfs(int y, int x, int islandIndex){
	queue<pair<pair<int, int>, int> > qu;
	qu.push(make_pair(make_pair(y, x), betweenLength[y][x]));

	while(!qu.empty()){
		pair<pair<int, int>, int > now = qu.front();
		qu.pop();
		for(int i = 0; i < 4; i++){
			int nextY = now.first.first + ypos[i];
			int nextX = now.first.second + xpos[i];
			int nowCost = now.second;
			if(map[nextY][nextX].first == 0 && betweenLength[nextY][nextX] > nowCost + 1
				&& nextY >= 1 && nextX >= 1 && nextY <= N && nextX <= N){
				betweenLength[nextY][nextX] = nowCost + 1;
				qu.push(make_pair(make_pair(nextY, nextX), nowCost + 1));
			}else if(map[nextY][nextX].second != 0 && map[nextY][nextX].second != islandIndex && nextY >= 1 && nextX >= 1 && nextY <= N && nextX <= N){
				betweenLength[nextY][nextX] = min(nowCost, betweenLength[nextY][nextX]);
				bridgeLength[map[nextY][nextX].second] = min(nowCost, bridgeLength[map[nextY][nextX].second]);
				bridgeLength[islandIndex] = min(nowCost, bridgeLength[islandIndex]);
			}
		}
	}
}






