#include <cstdio>
#include <queue>

using namespace std;

queue<pair<pair<int, int>, int> > qu;
pair<int, int> start, endPoint;

int mapSize;
void bfs();
int ypos[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int xpos[8] = {1, 2, -1, -2, -1, -2, 1, 2};

void input();

int main(){
	input();
}

void input(){
	int testCase;
	
	scanf("%d", &testCase);

	for(int cs = 0; cs < testCase; cs++){
		scanf("%d", &mapSize);
		scanf("%d %d", &start.first, &start.second);
		scanf("%d %d", &endPoint.first, &endPoint.second);
		bfs();
		while(!qu.empty())
			qu.pop();

		
	}

}

void bfs(){
	int map[302][302] = { 0, };
	map[start.first][start.second] = 1;
	qu.push(make_pair(make_pair(start.first, start.second), 0));

	while(!qu.empty()){
		pair<int, int> now = qu.front().first;
		int count = qu.front().second;
		qu.pop();
		
		if(now.first == endPoint.first && now.second == endPoint.second){
			printf("%d\n", count);
			break;
		}
		for(int i = 0; i < 8; i++){
			int nextY = now.second + ypos[i];
			int nextX = now.first + xpos[i];
			if(nextX>=0 && nextX < mapSize && nextY >= 0 &&  nextY < mapSize && !map[nextX][nextY]){
				qu.push(make_pair(make_pair(nextX, nextY), count + 1));
				map[nextX][nextY] = 1;
			}
		}
	}
}