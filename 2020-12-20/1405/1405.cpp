#include <cstdio>
#include <iostream>

int map[100][100];

int xPos[4] = { 1, -1, 0, 0};
int yPos[4] = { 0, 0, -1, 1};
int percentage[6], N;
double save = 0.0;
void dfs(int x, int y, int count, double percent);
int easyMove = 0, allMove = 0;

using namespace std;

int main(){
	
	scanf("%d", &N);

	for(int i = 0; i < 4; i++)
		scanf("%d", &percentage[i]);

	dfs(50, 50, 0, 1.0);
	cout.precision(11); cout << fixed;
	cout << save;
}

void dfs(int x, int y, int count, double percent){
	
	if(N == count){
		save+=percent;
		return;
	}
	map[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int newX = xPos[i] + x;
		int newY = yPos[i] + y;
		if(percentage[i] != 0 && map[newY][newX] == 0){
			dfs(newX, newY, count+1, percent * percentage[i]/100);
			map[newY][newX] = 0;	
		}
	}

}