#include <stdio.h>
#include <string.h>

int midResult = 0;
int sum = 0;
char brackets[32];
int canSum=0;
int viewIdx=-1;
char stack[32];

int isLeftBracket(char bracket);
void leftBraket(char bracket);
int rightBraket(char braket, int i);
void slashMidResult(int devide);
void midCalculate();

int main(){
	scanf("%s", &brackets);
	int length = strlen(brackets);

	if(length%2!=0){
		printf("0");
		return 0;
	}

	for(int i=0; i <length; i++){
		if(isLeftBracket(brackets[i])){
			leftBraket(brackets[i]);
		}else{
			if(rightBraket(brackets[i], i)==0)
				break;
		}
	}
	printf("%d", sum);
}

int isLeftBracket(char bracket){
	return bracket=='(' || bracket=='[';
}
void leftBraket(char bracket){
	canSum=1;
	viewIdx+=1;
	stack[viewIdx] = bracket;
	midResult = midResult==0? (bracket=='('?2:3):(bracket=='('?midResult*2:midResult*3);
}
int rightBraket(char braket, int i){
	if(braket == ')'){
		if(stack[viewIdx]=='('){
			midCalculate();
			slashMidResult(2);
		}else{
			sum=0;
			return 0;
		}
	}else {
		if(stack[viewIdx]=='['){
			midCalculate();
			slashMidResult(3);
		}else{
			sum=0;
			return 0;
		}
	}
	return 1;
}

void midCalculate(){
	if(canSum==1)
		sum+=midResult;
	canSum=0;

}

void slashMidResult(int devide){
	midResult/=devide;
	if(midResult==1)
		midResult=0;
	stack[viewIdx] = '\0';
	viewIdx-=1;
}
