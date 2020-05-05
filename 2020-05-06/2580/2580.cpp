#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int> > position;
int map[10][10];

void input();
void backTracking(int limit);
int isValidSdoko(int value, pair<int, int> position);

int main(){
	input();
	backTracking(0);
}

void input(){
	for(int y = 0; y < 9; y++){
		for(int x = 0; x < 9; x++){
			scanf("%d", &map[y][x]);
			if(!map[y][x])
				position.push_back(make_pair(y, x));
		}
	}
}

void backTracking(int limit){
	if(limit == position.size()){
		for(int y = 0; y < 9; y++){
			for(int x = 0; x < 9; x++){
				printf("%d ",map[y][x]);
			}
			printf("\n");
		}
		exit(0);
	}

	for(int number = 1; number <= 9; number++){
		if(isValidSdoko(number, position[limit])){
			int y = position[limit].first;
			int x = position[limit].second;
			map[y][x] = number;
			backTracking(limit+1);
			map[y][x] = 0;
		}
	}
}

int isValidSdoko(int value, pair<int, int> position){
	int yPos = position.first;
	int xPos = position.second;

	for(int x = 0; x < 9; x++)
		if(map[yPos][x] == value)
			return 0;

	for(int y = 0; y < 9; y++)
		if(map[y][xPos] == value)
			return 0;

	int threeStartY = position.first/3 * 3;
	int threeStartX = position.second/3 * 3;

	for(int y = threeStartY; y < threeStartY + 3; y++){
		for(int x = threeStartX; x < threeStartX + 3; x++){
			if(map[y][x] == value)
				return 0;
		}
	}

	return 1;
}