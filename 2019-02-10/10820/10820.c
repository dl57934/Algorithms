#include <stdio.h>
#include <string.h>

typedef struct _board{
	int lower;
	int upper;
	int number;
	int empty;
}board;

board boardScore;

void boardInit(){
	boardScore.lower=0;
	boardScore.upper=0;
	boardScore.number=0;
	boardScore.empty=0;
}



int isLower(char letter){
	return letter >= 'a' && letter <= 'z';
}

int isUpper(char letter){
	return letter >= 'A' && letter <= 'Z';	
}

int isNumber(char letter){
	return letter >= '0' && letter <= '9';	
}

int main(){
	char depscription[104];
	boardInit();

	while(fgets(depscription, 100, stdin)){

		int length = strlen(depscription);

		for(int i =0; i < length; i++){
			if(isLower(depscription[i]))
				boardScore.lower+=1;
			else if(isUpper(depscription[i]))
				boardScore.upper+=1;
			else if(isNumber(depscription[i]))
				boardScore.number+=1;
			else if(depscription[i] =='\n'){
				printf("%d %d %d %d\n", boardScore.lower, boardScore.upper, boardScore.number, boardScore.empty);
				boardInit();
		}
		else{
			boardScore.empty+=1;
		}
		}
	}
}