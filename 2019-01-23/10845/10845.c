#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void whatOrder(char order[]);
void init();
void push(int value);
int pop();
int size();
int empty();
int front();
int back();

typedef struct _queue{
	struct _queue *next;
	int value;
	int size;
}queue;

queue *qu;
queue *last;

int main(N){
	char order[10];

	scanf("%d", &N);
	init();
	for(int i=0; i < N; i++){
		scanf("%s", order);
		whatOrder(order);
	}
}

void whatOrder(char order[]){
	if(!strcmp(order, "push")){
		int value;
		scanf("%d", &value);
		push(value);
 	}else if(!strcmp(order, "pop")){
 		printf("%d\n", pop());
 	}
 	else if(!strcmp(order, "size")){
 		printf("%d\n", size());
 	}
 	else if(!strcmp(order, "empty")){
 		printf("%d\n", empty());
 	}
 	else if(!strcmp(order, "front")){
 		printf("%d\n", front());
 	}
 	else if(!strcmp(order, "back")){
 		printf("%d\n",back());
 	}
}

void init(){
	qu = malloc(sizeof(queue));
	qu->size =0;
	qu->value=0;

	last = qu;
}

void push(int value){
	if(qu->size == 0){
		qu->value = value;
		qu->next = malloc(sizeof(queue));
		last = qu;
	}
	else{
		queue *temp = malloc(sizeof(queue));
		temp->value = value;
		temp->next = malloc(sizeof(queue));
		last->next = temp;
		last = last->next;
	}
	qu->size+=1;
}

int pop(){
	if(qu->size == 0)
		return -1;
	else{
		int result = qu->value;
		qu->next->size = qu->size-1;
		qu = qu->next;
		return result;
	}
}

int size(){
	return qu->size;
}

int empty(){
	if(qu->size == 0)
		return 1;
	return 0;
}
int front(){
	if(qu->size == 0)
		return -1;
	return qu->value;
}
int back(){
	if(qu->size == 0)
		return -1;
	return last->value;
}