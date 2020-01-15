#include <stdio.h>

char board[51][51] ={0,};
int initFlag = 0;
int flag = 0;
int min = 50*50;
int count = 0;

void checkRightPoint(char firstPoint, int width, int height);
void search(char firstPoint, int heightCheckCount, int widthCheckCount);
int main(){
	int N =0, M=0;
	
	scanf("%d %d", &N ,&M);
	fflush(stdin); 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			scanf("%c", &board[i][j]);		
		fflush(stdin); 
	}

	int heightCheckCount = 1 + N-8;
	int widthCheckCount = 1 + M-8;

	search('W', heightCheckCount, widthCheckCount);
	search('B', heightCheckCount, widthCheckCount);
	
	printf("%d\n", min);
}

void search(char firstPoint, int heightCheckCount, int widthCheckCount){
	for(int height = 0; height < heightCheckCount; height++){
		for(int width = 0; width < widthCheckCount; width++){
			for(int heigtAppendPoint = 0; heigtAppendPoint < 8; heigtAppendPoint++){
				for(int widthAppendPoint = 0; widthAppendPoint < 8; widthAppendPoint++){
					int heightIndex = height + heigtAppendPoint;
					int widthIndex = width + widthAppendPoint;
					checkRightPoint(firstPoint, widthIndex, heightIndex);
				}
			}
			if(min > count)
				min = count;
			count=0;
		}
	}
}

void checkRightPoint(char firstPoint, int width, int height){
	int index = width + height;
	if(firstPoint == 'W'){
		if((index%2==1 && board[height][width]!='B') || (index%2==0 && board[height][width]!='W'))
			count+=1;
	}
	else{
		if((index%2==1 && board[height][width]!='W') || (index%2==0 && board[height][width]!='B'))
			count+=1;
	}
}


