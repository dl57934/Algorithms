#include <cstdio>
#include <queue>
#include <stdlib.h>
using namespace std;
#define element pair<int, pair<int, int> > 
int map[127][127], visited[127][127], result[127][127];
int ypos[4] = {0, 1, 0, -1}, xpos[4] = {1, 0, -1, 0};
int N;
void solve(int problemNumber);
void dajickstra();

int main(){
	for(int i = 1; 1; i++)
		solve(i);
}

void solve(int problemNumber){
	scanf("%d", &N);

	if(N == 0)
		exit(0);

	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			scanf("%d", &map[y][x]);
			result[y][x] = 987654321;
			visited[y][x] = 0;
		}
	}

	result[0][0] = map[0][0];

	dajickstra();

	printf("Problem %d: %d\n", problemNumber, result[N-1][N-1]);
}


void dajickstra(){
	priority_queue <element, vector<element>, greater<element> > pq;
	pq.push(make_pair(map[0][0], make_pair(0, 0)));

	while(!pq.empty()){
		int nowCost = pq.top().first;
		pair<int, int> now = pq.top().second;
		int nowY = now.first, nowX = now.second;
		pq.pop();
		visited[nowY][nowX] = 1;
		for(int i = 0; i < 4; i++){
			int nextY = nowY + ypos[i];
			int nextX = nowX + xpos[i];
			if(visited[nextY][nextX] == 0 && nextY < N && nextY >= 0 && nextX < N && nextX >= 0){
				if(nowCost + map[nextY][nextX] < result[nextY][nextX]){
					result[nextY][nextX] = nowCost + map[nextY][nextX];
					pq.push(make_pair(result[nextY][nextX], make_pair(nextY, nextX)));
				}
			}
		}
	}
}