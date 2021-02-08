#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int xpos[9] = {-2, -1, 1, 2, -2, -1, 1, 2};
int ypos[9] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve();

int main(){
	int testCase;
	scanf("%d", &testCase);
	for(int i = 0; i < testCase; i++)
		solve();
}

void solve(){
	int visit[302][302] = {0,};
	int startY, startX, endY, endX;
	int size;
	queue<pair<int, pair<int, int> > > qu;

	scanf("%d", &size);

	scanf("%d %d %d %d", &startY, &startX, &endY, &endX);

	qu.push(make_pair(0, make_pair(startY, startX)));

	visit[startY][startX] = 1;

	while(!qu.empty()){
		int weight = qu.front().first;
		pair<int, int> now = qu.front().second;
		qu.pop();
		if(now.first == endY && now.second == endX){
			printf("%d\n", weight);
			return;
		}

		for(int i = 0; i < 9; i++){
			int nextY = now.first + ypos[i];
			int nextX = now.second + xpos[i];

			if(nextY >= 0 && nextY < size && nextX >= 0 && nextX < size){
				if(visit[nextY][nextX] == 0){
					visit[nextY][nextX] = 1;
					qu.push(make_pair(weight+1, make_pair(nextY, nextX)));
				}
			}
		}
	}
}