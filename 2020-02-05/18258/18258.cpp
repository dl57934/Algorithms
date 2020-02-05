#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;

void commandOrder(char order[]);
void init();
void push(int data);
int pop();
int front();
int back();
int size();
int empty();

queue <int> q;

int main(){
	int N;
	scanf("%d", &N);
	char order[1002];
	fflush(stdin);
	for(int i = 0; i < N; i++){
		scanf("%s", order);
		commandOrder(order);
	}
}

void commandOrder(char order[]){
	if(!strcmp(order,"push")){
		int data;
		scanf("%d", &data);
		push(data);
	}
	else if(!strcmp(order, "pop"))
		printf("%d\n", pop());
	else if(!strcmp(order, "front"))
		printf("%d\n", front());
	else if(!strcmp(order, "back"))
		printf("%d\n", back());
	else if(!strcmp(order, "size"))
		printf("%d\n", size());
	else if(!strcmp(order, "empty"))
		printf("%d\n", empty());
	
}

void push(int data){
	q.push(data);
}

int pop(){
	if(size()){
		int data = q.front();
		q.pop();
		return data;
	}
	return -1;
	
}

int front(){
	if(size())
		return q.front();
	return -1;
}

int back(){
	if(size())
		return q.back();
	return -1;
}

int size(){
	return q.size();
}

int empty(){
	if(size())
		return 0;
	return 1;	
}