#include <cstdio>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

queue <int> qu;
string command;

void whatCommand();
void print(int value);
void push(int value);
void pop();
void size();
void empty();
int isEmpty();
void front();
void back();

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		cin >> command;
		whatCommand();
	}
}

void whatCommand(){
	if(!command.compare("push")){
		int inputNum;
		scanf("%d", &inputNum);
		push(inputNum);
	}else if(!command.compare("pop"))
		pop();
	else if(!command.compare("size"))
		size();
	else if(!command.compare("empty"))
		empty();
	else if(!command.compare("front"))
		front();
	else if(!command.compare("back"))
		back();
	
}

void push(int value){
	qu.push(value);
}

void pop(){
	if(isEmpty())
		print(-1);
	else {
		print(qu.front());
		qu.pop();
	}
}

void size(){
	print(qu.size());
}

void empty(){
	if(isEmpty())
		print(1);
	else 
		print(0);
}

int isEmpty(){
	if(qu.empty())
		return 1;
	else 
		return 0;
}

void front(){
	if(isEmpty())
		print(-1);
	else
		print(qu.front()); 
}

void back(){
	if(isEmpty())
		print(-1);
	else
		print(qu.back());
}


void print(int value){
	printf("%d\n", value);
}

