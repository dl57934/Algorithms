#include <stdio.h>

int N, M;
char map[53][53];
int widthLimit, heightLimit;
void getMinimum();
int isRightPoint(int widthPoint, int heightPoint);
char startPoint;
int min = 10000000;
int checkChangePoint = 0;

int main(){
	scanf("%d %d", &N, &M);
	widthLimit = M-7;
	heightLimit = N-7;

	for(int j = 0; j < N; j++)
		scanf("%s", &map[j]);					
		
	startPoint = 'W';
	getMinimum();
	startPoint = 'B';
	getMinimum();

	printf("%d", min);

}

void getMinimum(){
	for(int startHeight = 0; startHeight < heightLimit; startHeight++){
		for(int startWidth = 0; startWidth < widthLimit; startWidth++){
			for(int height = startHeight; height < startHeight+8; height++){
				for(int width = startWidth; width < startWidth+8; width++){
					if(!isRightPoint(width, height))
						checkChangePoint+=1;
				}
			}
			if(min > checkChangePoint)
				min = checkChangePoint;
			checkChangePoint = 0;
		}
	}
}

int isRightPoint(int widthPoint, int heightPoint){
	if(startPoint == 'W'){
		if((widthPoint+heightPoint)%2 == 0 && map[heightPoint][widthPoint] == 'W')
			return 1;
		else if((widthPoint+heightPoint)%2 != 0 && map[heightPoint][widthPoint] == 'B')
			return 1;
		else 
			return 0;
	}else if(startPoint == 'B'){
		if((widthPoint+heightPoint)%2 == 0 && map[heightPoint][widthPoint] == 'B')
			return 1;
		else if((widthPoint+heightPoint)%2 != 0 && map[heightPoint][widthPoint] == 'W')
			return 1;
		else 
			return 0;
	}
	return 1;
}