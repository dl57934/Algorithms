#include <stdio.h>

int arr[1001][1001];

int isRight = 1;
int isLeft = 0;
int isDown = 0;
int isUp = 0;
int right = 1;
int checkRight = 0;
int down = 1;
int checkDown = 0;
int left = 1;
int checkLeft = 0;
int up = 2;
int checkUp = 0;


int main(){
	int N;
	int findValue = 0 ; 
	scanf("%d %d", &N, &findValue);
	int saveWidth, saveHeight;
	int width = N/2;
	int height = N/2;
	int occupy = 1;
	int startingNum = 1;
	for(int w = 1; w <= N; w++){
		for(int h = 1; h <= N; h++){
			arr[height][width] = occupy;
			if(findValue == occupy){
				saveWidth = width;
				saveHeight=height;
			}
			if(occupy == startingNum*startingNum){
				isUp=0;
				up+=2;
				checkUp= 0;
				height-=1;
				startingNum+=2;
				isRight=1;
			}else if(isRight){
				if(right == checkRight){
					isRight= 0;
					isDown=1;
					right+=2;
					checkRight = 0;
					height+=1;
				}else{
					checkRight+=1;
					width+=1;
				}
			}else if (isDown){
				if(down == checkDown){
					isDown= 0;
					isLeft=1;
					down+=2;
					checkDown= 0;
					width-=1;
				}
				else{	
					checkDown+=1;
					height+=1;
				}
			}else if (isLeft){
				if(left == checkLeft){
					isLeft= 0;
					isUp=1;
					left+=2;
					checkLeft= 0;
					height-=1;
				}else{
					checkLeft+=1;
					width-=1;
				}
			}else if (isUp){
					checkUp+=1;
					height-=1;
			}
			occupy+=1;
		}
	}
	for(int h = 0; h < N; h++){
		for(int w = 0; w < N; w++){
			printf("%d ", arr[h][w]);
		}
		printf("\n");
	}

	printf("%d %d\n",saveHeight+1, saveWidth+1);
}