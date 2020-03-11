#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

queue <pair<int, int> > qu;

int xpos[4] = {1, 0, -1, 0};
int ypos[4] = {0, 1, 0, -1};

int map[102][102];
int copyMap[102][102];

int N, M;

void input();
void escapeMirror();

int main(){
	input();
	N-=1, M-=1;

	escapeMirror();
	printf("%d", copyMap[N][M]);
}

void input(){
	scanf("%d %d", &N, &M);

	for(int y = 0; y < N; y++)
		for(int x = 0; x < M; x++)
			scanf("%1d", &map[y][x]);

	qu.push(make_pair(0, 0));
}

void escapeMirror(){
	copyMap[0][0] = 1;
	while(!qu.empty()){
		pair<int, int> point = qu.front();
		qu.pop();
		for(int i = 0; i < 4; i++){
			int ay = ypos[i] + point.first;  
			int ax = xpos[i] + point.second;
			if(map[ay][ax] && ay>=0 && ax>=0){
				map[ay][ax] = 0;
				copyMap[ay][ax] = copyMap[point.first][point.second] + 1;
				qu.push(make_pair(ay, ax));
			}
		}
	}
}