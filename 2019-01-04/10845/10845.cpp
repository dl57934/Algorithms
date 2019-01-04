#include <cstdio>
#include <string.h>
#include <queue>

#define PUSH "push"
#define POP "pop"
#define SIZE "size"
#define EMPTY "empty"
#define FRONT "front"
#define BACK "back"

void push(int num);
int pop();
int size();
int empty();
int front();
int back();
void print(int value);

using namespace std;

queue <int> qu;

int main(){
	int T;
	char order[10];
	int inputValue;
	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		scanf("%s", &order);
		if(!strcmp(order, PUSH)){
			scanf("%d", &inputValue);
			push(inputValue);
		}else if(!strcmp(order, POP))
			print(pop());
				
		else if(!strcmp(order, SIZE))
			print(size());
				
		else if(!strcmp(order, EMPTY))
			print(empty());
		
		else if(!strcmp(order, FRONT))
			print(front());
				
		else if(!strcmp(order, BACK))
			print(back());
	}
}

void print(int value){
	printf("%d\n", value);
}

void push(int num){
	qu.push(num);
}

int pop(){
	if(qu.empty())
		return -1;
	else{
		int returnVal = front();
		qu.pop();
		return returnVal;
	}
}

int size(){
	return qu.size();
}

int empty(){
	if(qu.empty())
		return 1;
	else 
		return 0;
}

int front(){
	if(qu.empty())
		return -1;
	else 
		return qu.front();
}

int back(){
	if(qu.empty())
		return -1;
	else 
		return qu.back();
}

