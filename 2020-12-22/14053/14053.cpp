#include <cstdio>

int N, M, r, c, direction;
int map[52][52];

int isFinish(int y, int x, int direction);

int main(){
	scanf("%d %d", &M, &N);
	scanf("%d %d %d", &r, &c, &direction); // direction 0 북쪽, 1 동쪽, 2 남쪽, 3 서
	
	int count = 1;

	for(int y = 0; y < M; y++){
		for(int x = 0; x < N; x++){
			scanf("%d", &map[y][x]);
		}
	}
	map[r][c] = -1;
	while(isFinish(r, c, direction)){
		for(int i = 0; i < 4; i++){
			int rotationDirection = direction-1 == -1? 3 : direction-1;	
			if(rotationDirection == 0){
				if(map[r-1][c] == 0){
					map[r-1][c] = -1;
					count +=1;
					r=r-1;
					direction = rotationDirection;
					break;
				}
			}else if(rotationDirection == 1){
				if(map[r][c+1] == 0){
					map[r][c+1] = -1;
					count +=1;
					c+=1;
					direction = rotationDirection;
					break;
				}
			}else if(rotationDirection == 2){
				if(map[r+1][c] == 0){
					map[r+1][c] = -1;
					count+=1;
					r+=1;
					direction = rotationDirection;
					break;
				}
			}else if(rotationDirection == 3){
				if(map[r][c-1] == 0){
					map[r][c-1] = -1;
					count +=1;
					c=c-1;
					direction = rotationDirection;
					break;
				}
			}
			direction = rotationDirection;
		}
	}
	
	printf("%d", count);

}

int isFinish(int y, int x, int direction){
	if( map[y][x+1] != 0 && map[y][x-1] != 0 && 
		map[y+1][x] != 0 && map[y-1][x] != 0){
		int back = direction <= 1? direction + 2 : direction - 2;
		if(back == 0){
			if(map[y-1][x] == 1)
				return 0;
			r = y-1;
			
		}else if(back == 1 ){
			if(map[y][x + 1] == 1)
				return 0;
			c = x+1;
		}else if(back == 2){
			if(map[y+1][x] == 1)
				return 0;
			r = y + 1;
		}else if(back == 3){
			if(map[y][x - 1] == 1)
				return 0;
			c = x-1;
		}
		return 1;
	}
	return 1;
}