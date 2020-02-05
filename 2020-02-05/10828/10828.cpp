#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

void push(int data);
int pop();
int top();
int empty();
void init();
void commandOrder(string order);

typedef struct Node{
	int size;
	int data;
	struct Node *nextNode;
}node;

node *stack;

int main(){
	int N;
	init();
	scanf("%d", &N);
	string order;
	for(int i = 0; i < N; i++){
		cin >> order;
		commandOrder(order);
	}
}

void commandOrder(string order){
	if(order == "push"){
		int number; 
		scanf("%d", &number);
		push(number);
	}else if(order == "top"){
		printf("%d\n", top());
	}else if(order == "empty"){
		printf("%d\n", empty());
	}else if(order == "pop"){
		printf("%d\n",  pop());
	}else if(order == "size"){
		printf("%d\n", stack->size);
	}
}

void init(){
	stack = (node*)malloc(sizeof(node));
	stack->size = 0;
	stack->nextNode = NULL;
}

void push(int data){
		node *newStack = (node*)malloc(sizeof(node));
		newStack->data = data;
		newStack->size = stack->size+1;
		newStack->nextNode =stack;
		stack = newStack;
}

int pop(){
	if(stack->size == 0)
		return -1;
 	else{
 		int result  = stack->data; 
 		stack = stack->nextNode;
 		return result;
 	}
}

int top(){
	if(stack->size == 0)
		return -1;
	return stack->data; 
}

int empty(){
	if(stack->size == 0)
		return 1 ;
	return 0;
}