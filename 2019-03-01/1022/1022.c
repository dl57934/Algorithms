#include <stdio.h>
#include <string.h>

int arr[10010][10010];

int isRight = 0;
int isLeft = 0;
int isDown = 0;
int isUp = 1;
int right = 2;
int checkRight = 0;
int down = 1;
int checkDown = 0;
int left = 1;
int checkLeft = 0;
int up = 1;
int checkUp = 0;


int main(){
	int r1, c1, r2, c2; 
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	r1+=5000, c1+=5000, r2+=5000, c2+=5000;
	int width = 10001/2;
	int height = 10001/2;
	int occupy = 1;
	int startingNum = 1;
	for(int w = 1; w <= 10001; w++){
		for(int h = 1; h <= 10001; h++){
			arr[height][width] = occupy;
			if(occupy == startingNum*startingNum){
				isRight=0;
				right+=2;
				width+=1;
				startingNum+=2;
				isUp=1;
			}else if(isUp){
				if(up == checkUp){
					isUp= 0;
					isLeft=1;
					up+=2;
					checkUp = 0;
					width-=1;
				}else{
					checkUp+=1;
					height-=1;
				}
			}
			else if (isLeft){
				if(left == checkLeft){
					isLeft= 0;
					isDown=1;
					left+=2;
					checkLeft=0;
					height+=1;
				}
				else{	
					checkLeft+=1;
					width-=1;
				}
			}else if (isDown){
				if(down == checkDown){
					isDown= 0;
					isRight=1;
					down+=2;
					checkDown= 0;
					width+=1;
				}else{
					checkDown+=1;
					height+=1;
				}
			}else if (isRight){
					width+=1;
			}
			occupy+=1;
		}
	}
	int N =arr[r1][r2];
	int i = 0;
	while(N > 0){
		i++;
		N/=10;
	}
	for(int h = r1; h <= r2; h++){
		for(int w = c1; w <= c2; w++){
			printf("%*d ",i ,arr[h][w]);
		}
		printf("\n");
	}
}