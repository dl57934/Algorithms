#include <stdio.h>

void makeStars(int inputSpace, int index);
void makeTri(int line);
void oddPlay(int space);
void evenPlay(int space);
char *Stars[3] = {"*", "* *", "*****"};
int betweenSpace = 0;
int firstSpace = 0;
int odd = 1, even = 2;
int iterator=0;


int main(line){
	scanf("%d", &line);
	makeTri(line);
}

void makeTri(int line){
	firstSpace = (line*2-1)/2;
	for(int i=1;i<=line/3;i++){
		makeStars(firstSpace, i);
	}	
}

void makeStars(int inputSpace, int index){
	if(index %2==1){
		//홀슈
		evenPlay(inputSpace);
		betweenSpace = index*3*2-1;
	}else{
		//짝수
		oddPlay(inputSpace);
		betweenSpace = index*3*2-1;
	}
	// if(index % 3 ==0){
	// 	betweenSpace = 2*index-1;
	// 	if((betweenSpace / 5)% 2 == 0){
	// 		//짝수
	// 		evenPlay(betweenSpace, index);
	// 		betweenSpace-=2;
	// 	}else {
	// 		oddPlay(betweenSpace, index);
	// 	}
	// }
	firstSpace-=3;

	printf("\n");
}

void oddPlay(int space){
	for(int i =0; i<3;i++){
		for(int i = 0;i<space;i++)
			printf(" ");
		space-=1;
	}
}

void evenPlay(int space){
	for(int i =0; i<3;i++){
		for(int i = 0;i<space;i++)
			printf(" ");
		printf("%s\n", Stars[i]);
		for(int i = 0; i <betweenSpace;i++)
			printf(" ");
		betweenSpace-=2;
		space-=1;
	}
}