#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEQUE_SIZE_ZERO 0
#define PUSH_FRONT "push_front"
#define PUSH_BACK "push_back"
#define POP_FRONT "pop_front"
#define POP_BACK "pop_back"
#define SIZE "size"
#define EMPTY "empty"
#define FRONT "front"
#define BACK "back"

typedef struct _node{
	int value;
	struct _node *front;
	struct _node *back;
}node;

node *deque;
node *last;
int dequeSize = 0;

void init();
void whatIsOrder(char order[]);
void push_front(int value);
void push_back(int value);
node* making_node(int value);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();

int main(){
	int N;
	char order[14];
	init();
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", order);
		whatIsOrder(order);
	}
}

void init(){
	deque = malloc(sizeof(node));
	deque->front = malloc(sizeof(node));
	deque->back = malloc(sizeof(node));
	last = deque;
}



void whatIsOrder(char order[]){
	if(strcmp(order, PUSH_FRONT)==0){
			int value; 
			scanf("%d", &value);
			push_front(value);
		}
		else if(strcmp(order, PUSH_BACK)==0){
			int value; 
			scanf("%d", &value);
			push_back(value);
		}	
		else if(strcmp(order, POP_FRONT)==0){
			printf("%d\n", pop_front());
		}
		else if(strcmp(order, POP_BACK)==0){
			printf("%d\n", pop_back());
		}
		else if(strcmp(order, SIZE)==0){
			printf("%d\n",size());
		}
		else if(strcmp(order, EMPTY)==0){
			printf("%d\n",empty());
		}	
		else if(strcmp(order, FRONT)==0){
			printf("%d\n",front());
		}
		else if(strcmp(order, BACK)==0){
			printf("%d\n",back());	
		}			
}

void push_front(int value){
	if(dequeSize == 0){
		deque->value = value;
		dequeSize++;
	}else{
		node* temp = making_node(value);
		deque->front = temp;
		temp->back = deque;
		deque = temp;
	}
}

void push_back(int value){
	if(dequeSize == 0){
		deque->value = value;
		dequeSize++;
	}else{
		node* temp = making_node(value);
		last->back = temp;
		temp->front = last;
		last = temp;
	}
}

node* making_node(int value){
	dequeSize++;
	node* temp = malloc(sizeof(node));
	temp->back = malloc(sizeof(node));
	temp->front = malloc(sizeof(node));
	temp->value = value;
	return temp;
}

int pop_front(){
	if(dequeSize == DEQUE_SIZE_ZERO)
		return -1;
	if(dequeSize == 1){
		int result = deque->value;	
		dequeSize--;
		return result;
	}else{
		int result = deque->value;
		deque = deque->back;
		dequeSize--;
		return result;
	}
}

int pop_back(){
	if(dequeSize == DEQUE_SIZE_ZERO)
		return -1;
	if(dequeSize == 1){
		int result = deque->value;	
		dequeSize--;
		return result;
	}else{
		int result = last->value;
		last = last->front;
		dequeSize--;
		return result;
	}
}

int size(){
	return dequeSize;
}

int empty(){
	if(dequeSize == DEQUE_SIZE_ZERO)
		return 1;
	return 0;
}

int front(){
	if(dequeSize == DEQUE_SIZE_ZERO)
		return -1;
	return deque->value;
}

int back(){
	if(dequeSize == DEQUE_SIZE_ZERO)
		return -1;
	return last->value;
}
