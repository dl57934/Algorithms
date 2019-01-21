#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int element;
typedef struct stack{
	element value;
	struct stack *next;
	int size;
}stack;

stack *st;
stack *first;

int command(char order[]);
void push(int value);
int pop();
int size();
int empty();
int top();
void init();

int main(N){
	char order[8];
	int result;
	init();
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%s", order);
		result = command(order);
		if(result != -2)
			printf("%d\n", result);
	}


}

int command(char order[]){
	if(!strcmp(order, "push")){
		int value; 
		scanf("%d", &value);
		push(value);
	}
	else if(!strcmp(order, "pop"))
		return pop();
	else if(!strcmp(order, "size"))
		return size();
	else if(!strcmp(order, "empty"))
		return empty();
	else if(!strcmp(order, "top"))
		return top();
	return -2;
}

void init(){
	st = malloc(sizeof(stack));
	st->next = NULL;
	st->value = 0; 
	st->size=0;
}

void push(int value){
	stack* temp = malloc(sizeof(stack));
	temp->value = value;
	temp->size= st->size;
	temp->next = st;
	st = temp;
	st->size++;
}

int pop(){
	if(st->size == 0)
		return -1;
	else {
		int result = st->value;
		st = st->next;
		return result;
	}
}
int size(){
	return st->size;
}
int empty(){
	if(st->size == 0)
		return 1;
	else 
		return 0;
}
int top(){
	if(st->size==0)
		return -1;
	else 
		return st->value;
}