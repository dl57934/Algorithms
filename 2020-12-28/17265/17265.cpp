#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
#include <stdlib.h>
using namespace std;

queue <pair<pair<int, int>, int > > qu;
char map[7][7];
int ypos[4] = {0, 1, 0, -1}, xpos[4] = {1, 0, -1, 0};
int N;

int solve(int type);

int main(){
	scanf("%d", &N);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			scanf(" %c", &map[y][x]);
		}
	}

	printf("%d %d", solve(0), solve(1));
}

int solve(int type){
	int dp[7][7] = { 0, }, visit[7][7];
	qu.push(make_pair(make_pair(1, 1), map[1][1] - '0'));
	dp[1][1] = map[1][1] - '0';

	if(type == 0){
		for(int y = 1; y <= 5; y++){
			for(int x = 1; x <=5; x++){
				dp[y][x] = INT_MIN;
				visit[y][x] = 0;
			}
		}
		while(!qu.empty()){
			pair<int,int> now = qu.front().first;
			int distance = qu.front().second;
			qu.pop();
			visit[now.first][now.second] = 1;
			for(int i = 0; i < 4; i++){
				int newY = now.first + ypos[i];
				int newX = now.second + xpos[i];
				if(newY >=1 && newY <= N && newX >= 1 && newX <= N && visit[newY][newX] != 1){
					
					if(map[newY][newX] == '*' || map[newY][newX] == '+' || map[newY][newX] == '-'){
						if(dp[newY][newX] < distance){
							dp[newY][newX] = distance;
							qu.push(make_pair(make_pair(newY, newX), distance));
						}
					}else{
						if(map[now.first][now.second] == '*'){
							if(distance * (map[newY][newX] - '0') > dp[newY][newX]){
								dp[newY][newX] = distance * (map[newY][newX] - '0');
								qu.push(make_pair(make_pair(newY, newX), dp[newY][newX]));
							}
						}else if(map[now.first][now.second] == '-'){
							if(distance - (map[newY][newX]-'0') > dp[newY][newX]){
								dp[newY][newX] = distance - (map[newY][newX] - '0');
								qu.push(make_pair(make_pair(newY, newX), dp[newY][newX]));
							}
						}else if(map[now.first][now.second] == '+'){
							if(distance + (map[newY][newX] -'0')> dp[newY][newX]){
								dp[newY][newX] = distance + (map[newY][newX] -'0');
								qu.push(make_pair(make_pair(newY, newX), dp[newY][newX]));
							}
						}
					}
				}
			}
		}
	}else{
		for(int y = 1; y <= 5; y++){
			for(int x = 1; x <=5; x++){
				dp[y][x] = INT_MAX;
				visit[y][x] = 0;
			}
		}
		while(!qu.empty()){
			pair<int,int> now = qu.front().first;
			int distance = qu.front().second;
			qu.pop();
			visit[now.first][now.second] = 1;
			for(int i = 0; i < 4; i++){
				int newY = now.first + ypos[i];
				int newX = now.second + xpos[i];
				if(newY >=1 && newY <= N && newX >= 1 && newX <= N && visit[newY][newX] != 1){
					
					if(map[newY][newX] == '*' || map[newY][newX] == '+' || map[newY][newX] == '-'){
						if(dp[newY][newX] > distance){
							dp[newY][newX] = distance;
							qu.push(make_pair(make_pair(newY, newX), distance));
						}
					}else{
						if(map[now.first][now.second] == '*'){
							if(distance * (map[newY][newX] - '0') < dp[newY][newX]){
								dp[newY][newX] = distance * (map[newY][newX] - '0');
								qu.push(make_pair(make_pair(newY, newX), dp[newY][newX]));
							}
						}else if(map[now.first][now.second] == '-'){
							if(distance - (map[newY][newX]-'0') < dp[newY][newX]){
								dp[newY][newX] = distance - (map[newY][newX] - '0');
								qu.push(make_pair(make_pair(newY, newX), dp[newY][newX]));
							}
						}else if(map[now.first][now.second] == '+'){
							if(distance + (map[newY][newX] -'0') < dp[newY][newX]){
								dp[newY][newX] = distance + (map[newY][newX] -'0');
								qu.push(make_pair(make_pair(newY, newX), dp[newY][newX]));
							}
						}
					}
				}
			}

		}
	}
	return dp[N][N];
}