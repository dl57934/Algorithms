#include <cstdio>

int map[15][15];

int main(){
	int T, liveFloor, liveRoom;
	scanf("%d", &T);

	for(int firstFloor = 0; firstFloor <= 14; firstFloor++)
		map[0][firstFloor] = firstFloor;

	for(int floor = 1; floor <= 14; floor++){
		int member = 0;
		for(int room = 1; room <= 14; room++){
			member+= map[floor-1][room];
			map[floor][room] = member;
		}
	}

	for(int i = 0; i < T; i++){
		scanf("%d %d", &liveFloor, &liveRoom);
		printf("%d\n", map[liveFloor][liveRoom]);
	}
}