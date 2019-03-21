#include <iostream>
#include <stack>
#include <string>
#include <cstdio>

#define SAME 0

using namespace std;

stack <int> st;
string command;

void whatKindCommand();
void top();
void empty();
void push(int value);
void pop();
void size();

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		cin >> command; 
		whatKindCommand();
	}
}


void whatKindCommand(){
	if(command.compare("push") == SAME){
		int value;
		scanf("%d", &value);
		push(value);
	}else if(command.compare("top") == SAME){
		top();
	}else if(command.compare("size") == SAME){
		size();
	}else if(command.compare("empty") == SAME){
		empty();
	}else if(command.compare("pop") == SAME){
		pop();
	}
}

void push(int value){
	st.push(value);
}

void top(){
	if(st.empty())
		printf("-1\n");
	else
		printf("%d\n", st.top());
}

void size(){
	printf("%d\n", st.size());
}

void empty(){
	if(st.empty())
		printf("1\n");
	else
		printf("0\n");
}

void pop(){
	if(st.empty())
		printf("-1\n");
	else{
		printf("%d\n", st.top());
		st.pop();
	}
}