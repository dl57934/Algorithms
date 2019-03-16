#include <cstdio>
#include <string.h>
#include <stack>

using namespace std;

int isLeftBrackets(char bracket);
void leftBrackets(char bracket);
int rightBrackets(char bracket, char prevBracket);
int isOddNumber(int length);
int result = 0;
int base = 0;
int isCanPlus = 1;
char brackets[50];
stack<int> st;

int main(){
	scanf("%s", brackets);
	int length = strlen(brackets);

	if(isOddNumber(length)){
		printf("0");
		return 0;
	}

	for(int i = 0; i < length; i ++){
		if(isLeftBrackets(brackets[i])){
			st.push(brackets[i]);
			leftBrackets(brackets[i]);
		}
		else{
			if(!st.empty()){
				if(rightBrackets(brackets[i], st.top())==0){
					printf("0");
					return 0;
				}}
			else {
				printf("0");
					return 0;
			}
		}	
	}
	printf("%d", result);
}

int isOddNumber(int length){
	return length%2!=0;
}

int isLeftBrackets(char bracket){
	if( bracket == '(' || bracket == '[')
		return 1;
	return 0;  
}

void leftBrackets(char bracket){
	if(bracket == '['){
		if(base == 0)
			base=3;
		else {
			base*=3;
		}
	}
	else{
		if(base == 0)
			base=2;
		else{
			base*=2;
		}
	}
	isCanPlus=1;	
}

int rightBrackets(char bracket, char prevBracket){
	if(bracket==']' && prevBracket=='['){
		if(isCanPlus){
			result+=base;
			isCanPlus=0;
		}
		base/=3;
		if(base == 1)
			base=0;
	}else if(bracket==')' && prevBracket=='('){
		if(isCanPlus){
			result+=base;
			isCanPlus=0;
		}
		base/=2;
		if(base == 1)
			base=0;
	}else 
		return 0;
	st.pop();
	return 1;
}

