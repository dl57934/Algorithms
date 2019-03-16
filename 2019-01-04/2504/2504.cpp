#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

stack <char> st;
int innerNumber = 0;
int result = 0;
int iscanAdd =0;

void calculInnerNum(char top);
void devide(int num);
void append();
void push(char bracekt);
int isWrongBracekt();
int isRightCircleBrackets();
int isRightBrackets();
int isLeftBrackets();
int leftBrackets(char temp[], int index);
int rightBrackets(char temp[], int index);

int main(){
	char brackets[32];
	scanf("%s", brackets);
	int length = strlen(brackets);

	for(int i = 0; i < length; i++)
		push(brackets[i]);

	int final = isWrongBracekt();
	printf("%d", final);

}

void push(char bracekt){
	st.push(bracekt);
}


int isWrongBracekt(){
	char temp[32];
	int index = 0;
	while(!st.empty()){
		if(isRightBrackets()){
			index = rightBrackets(temp, index);
		}else if(isLeftBrackets()){
			index = leftBrackets(temp, index);
			if(index == -1)
				return 0;
		}
	}
	if(strlen(temp) > 0)
		return 0;
	return result;
}

int isRightBrackets(){
	return st.top() == ')' || st.top() == ']'; 
}

int isLeftBrackets(){
	return st.top() == '(' || st.top() == '['; 
}

int leftBrackets(char temp[], int index){
	if(st.top() == '('){
		if(temp[index-1] != ')')
			return -1;
		else{
			if(iscanAdd)
				append();
			
			devide(2);
			
			temp[index-1] ='\0';
			index-=1;
			st.pop();
			return index;
		}
	} else if(st.top() == '['){
		if(temp[index-1] != ']')
			return -1;
		else{
			if(iscanAdd)
				append();
			
			devide(3);
			temp[index-1] ='\0';
			index-=1;
			st.pop();
			return index;
		}
	}
}

void devide(int num){
	if(innerNumber/num == 1)
		innerNumber = 0;
	else
		innerNumber/=num; 
}



void append(){
	result+=innerNumber;
	iscanAdd = 0;
}

int rightBrackets(char temp[], int index){
	iscanAdd =1;
	char top = st.top();
	
	calculInnerNum(top);
	temp[index] = top;
	index+=1;
	st.pop();
	return index;
}

void calculInnerNum(char top){
	if(innerNumber == 0){
		if(top == ')')
			innerNumber = 2;
		else
			innerNumber = 3;
	}else{
		if(top == ')')
			innerNumber *= 2;
		else
			innerNumber *= 3;
	}
}

int isRightCircleBrackets(){
	return st.top()==')';
}


























