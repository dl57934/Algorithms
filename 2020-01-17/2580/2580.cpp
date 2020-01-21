#include <stdio.h>

int sdoku[11][11];

int isRightSdoku(int width, int height);
void makeRightSdoku(int width, int height);

int main(){
	for(int height = 0; height < 9; height++)
		for(int width = 0; width < 9; width++)
			scanf("%d", &sdoku[height][width]);

	

	for(int height = 0; height < 9; height++){
		for(int width = 0; width < 9; width++){
			printf("%d ", sdoku[height][width]);	
		}
		printf("\n");
	}
}

int isRightSdoku(int width, int height){

}

void makeRightSdoku(int width, int height){

}