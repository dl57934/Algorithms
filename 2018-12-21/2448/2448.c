#include <stdio.h>

void makeStars(int space, int check, int newBetweenSpace, int index, int firstIndex);
void makeTri(int line);

char *Stars[3] = {"*", "* *", "*****"};
int betweenSpace = 0;
int space = 0;

int main(line){
	scanf("%d", &line);
	makeTri(line);
}

void makeTri(int line){
	space = (line*2-1)/2;
	for(int i=1;i<=line;i++){
		if(i%3==0 && i>=3) 
			makeStars(space, 1,i*2-1, 3, i);
		else
			makeStars(space, 0, 0, i%3, i);
	}	
}

void makeStars(int inputSpace, int check, int newBetweenSpace, int index,int firstIndex){
		for(int i = 0; i < inputSpace;i++)
			printf(" ");
		printf("%s",Stars[index-1]);
		for(int j = 0; j < betweenSpace; j++)
			printf(" ");
		if(firstIndex > 3)
		printf("%s",Stars[index-1]);
		if(check){
			printf("%d", newBetweenSpace);
			betweenSpace = newBetweenSpace;
		}else{
			betweenSpace-=2;
		}
		space-=1;
		printf("\n");
}