#include <string>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <math.h>
using namespace std;

queue <pair<int, int> > qu;
int map[103][103];
int minCost = 123123123;

int N, M;
int xpos[4] = {1, 0, -1, 0};
int ypos[4] = {0, 1, 0, -1};
int escapeMirror();
int getDistance(int y, int x);

int main(){
	
	string oneLine;

	scanf("%d %d", &N, &M);

	for(int y = 0; y < N; y++)
		for(int x = 0; x < M; x++)
			scanf("%1d", &map[y][x]);
	
	M-=1;
	N-=1;
	qu.push(make_pair(0, 0));
	escapeMirror();
	printf("%d\n", map[N][M]);
	

}

int escapeMirror(){
	map[0][0] = 1;
	int pushX=0, pushY=0;
	int count = 1;
	while(!qu.empty()){
		pair<int, int> point = qu.front();
		qu.pop();
		for(int i = 0; i < 4; i++){
			int ax = point.second + xpos[i];
			int ay = point.first + ypos[i];
			if(ax >= 0 && ay>=0 && ax <= M&& ay<= N&& map[ay][ax] == 1){
				qu.push(make_pair(ay, ax));
				map[ay][ax] = map[point.first][point.second]+1;
				count+=1;
			}
		}
	}
	return count;
}

int getDistance(int y, int x){
	return sqrt(pow(N-y,2) + pow(M-x,2));
}