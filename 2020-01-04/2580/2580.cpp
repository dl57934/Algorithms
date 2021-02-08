#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;
vector <pair<int, int> > vc;
int map[11][11];

int isValidSdoko(pair<int,int> position);
void backTrack(int limit);

int main(){
	for(int y = 0; y < 9; y++){
		for(int x = 0; x < 9; x++){
			scanf("%d", &map[y][x]);
			if(map[y][x] == 0)
			vc.push_back(make_pair(y, x));
		}
	}

	backTrack(0);
}


void backTrack(int limit){
	if(limit == vc.size()){
		for(int y = 0; y < 9; y++){
			for(int x = 0; x < 9; x++){
				printf("%d ", map[y][x]);
			}
			printf("\n");
		}
		exit(0);
	}

	int y = vc[limit].first, x = vc[limit].second;
	for(int i = 1; i <= 9; i++){
		map[y][x] = i;
		if(isValidSdoko(vc[limit])){
			backTrack(limit + 1);
		}
		map[y][x] = 0;
	}
}

int isValidSdoko(pair<int,int> position){
	int y = (position.first/3) * 3;
	int x = (position.second/3) * 3;

	int ycheck[11] = {0, };
	for(int yy = 0; yy < 9; yy++){
		if(ycheck[map[yy][position.second]] == 1 && map[yy][position.second] != 0){
			return 0;
		}
		ycheck[map[yy][position.second]] = 1;
	}

	int xcheck[11] = {0, };
	for(int xx = 0; xx < 9; xx++){
		if(xcheck[map[position.first][xx]] == 1 && map[position.first][xx] != 0){
			return 0;
		}
		xcheck[map[position.first][xx]] = 1;
	}

	int checkNum[11] = {0, };
	for(int yy = 0; yy < 3; yy++){
		for(int xx = 0; xx < 3; xx++){
			if(map[y + yy][x + xx] != 0 && checkNum[map[y + yy][x + xx]] == 1){
				return 0;
			}
			checkNum[map[y + yy][x + xx]] = 1;
		}
	}

	return 1;
}