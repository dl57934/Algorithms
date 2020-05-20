#include <cstdio>
#include <vector>

using namespace std;

char map[9][9];

int main(){
	char pin;
	int count = 0;
	
	for(int y = 1; y <= 8; y++){
		for(int x = 1; x <= 8; x++){
			scanf(" %c", &map[y][x]);
			if(map[y][x] =='F' && (x+y)%2 == 0 ){
				count++;
			}
		}
	}

	printf("%d", count);
}