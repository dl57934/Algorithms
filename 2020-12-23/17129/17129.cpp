#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#define ll long long

using namespace std;

int n, m;
int xpos[4] = {0, 1, 0, -1}, ypos[4] = {1, 0, -1, 0};
char temp[3003];
string map[3003];
int visited[3003][3003];
pair<ll, ll> startPoint;
int minDistance = INT_MAX;
void bfs();

int main(){
	scanf("%d %d", &n, &m);
	
	for(int y = 0; y < n; y++){
		fflush(stdin);
		scanf("%s", &temp);
		map[y] = temp;
		for(int x = 0; x < m; x++){
			if(map[y][x] == '2'){
				startPoint.first = y;
				startPoint.second = x;
			}
		}
	}

	bfs();

	if(minDistance == INT_MAX)
		printf("NIE");
	else{
		printf("TAK\n%d", minDistance);
	}
}

void bfs(){
	queue <pair<pair<ll, ll>, ll> > qu;
	qu.push(make_pair(make_pair(startPoint.first, startPoint.second), 0));
	
	while(!qu.empty()){
		pair<ll, ll> now = qu.front().first;
		ll distance = qu.front().second;
		qu.pop();

		for(int i = 0; i < 4; i++){
			ll nextY = now.first + ypos[i];
			ll nextX = now.second + xpos[i];
			if(nextY == -1 || nextX == -1 || nextY >= n || nextX >= m)
				continue;

			if(map[nextY][nextX] != '1' && visited[nextY][nextX] == 0){
				if(map[nextY][nextX] == '3' || map[nextY][nextX] == '4' || map[nextY][nextX] == '5'){
					minDistance = distance+1;
					return;
				}
				qu.push(make_pair(make_pair(nextY, nextX), distance+1));
				visited[nextY][nextX] = 1;
			}
		}
	}
}