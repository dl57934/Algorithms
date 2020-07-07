#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector <pair<int, int> > land;

vector <int> vc;
int N, M;
int findMax = 0;
int map[53][53];
int copyMap[53][53];
int ypos[4] = {0, 1, 0, -1};
int xpos[4] = {1, 0, -1, 0};
void init();
void input();
void treasure();
void bfs(int y, int x);
int isValidSection(int newY, int newX);
int main(){
	input();
	treasure();
}

void init(){
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			copyMap[y][x] = 0;
		}
	}
}

void input(){
	
	char island;
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf(" %c", &island);
			if(island == 'L'){
				map[y][x] = 1;
				land.push_back(make_pair(y, x));
			}else{
				map[y][x] = 0;
			}
		}
	}
}

void treasure(){
	for(auto startLand : land){
		pair<int, int> target = startLand;
		bfs(startLand.first, startLand.second);
		init();
	}	
	printf("%d", findMax);
}

void bfs(int y, int x){
	queue <pair<pair<int, int>, int> > qu;
	int check[52][52] = {0, };

	qu.push(make_pair(make_pair(y, x), 0));
	check[y][x] = 1;

	while(!qu.empty()){
		pair<int, int> now = qu.front().first;
		int distance = qu.front().second;
		int nowY = now.first;
		int nowX = now.second;
		check[nowY][nowX] = 1;
		qu.pop();
		for(int pos = 0; pos < 4; pos++){
			int newY = nowY + ypos[pos];
			int newX = nowX + xpos[pos];
			if(isValidSection(newY, newX) && !check[newY][newX]){
				if((copyMap[newY][newX] > distance + 1 || copyMap[newY][newX] == 0) && map[newY][newX] == 1){
					if(findMax < distance+1){
						findMax = distance+1;
					}
					copyMap[newY][newX] =  distance + 1;
					qu.push(make_pair(make_pair(newY, newX), distance+1));
				}
			}
		}
	}
}

int isValidSection(int newY, int newX){
	if(newY>=1 && newX>=1 && newY<=N && newX<=M)
		return 1;
	return 0;
}







