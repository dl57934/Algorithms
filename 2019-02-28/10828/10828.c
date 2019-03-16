#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
	int value;
	struct _node *next;
	int size;
}stack;

stack *st;

void init();
void whichOrder(char order[]);

int main(){
	int N;
	char order[8]; 
	scanf("%d", &N);
	init();
	for(int i = 0; i < N; i++){
		scanf("%s", order);
		whichOrder(order);
	}
}

void init(){
	st = malloc(sizeof(stack));
	st->value = 0;
	st->next = NULL;
	st->size = 0;
}

void whichOrder(char order[]){
	if(!strcmp(order, "push")){
		int num;
		scanf("%d", &num);
		stack *newNode = malloc(sizeof(stack));
		newNode->size = st->size+1;
		newNode->value = num;
		newNode->next = st;
		st = newNode;
	}else if(!strcmp(order, "top")){
		if(st->size ==0)
			printf("-1\n");
		else 
			printf("%d\n", st->value);
	}else if(!strcmp(order, "size")){
		printf("%d\n", st->size);
	}else if(!strcmp(order, "empty")){
		if(st->size == 0)
			printf("1\n");
		else
			printf("0\n");
	}else if(!strcmp(order, "pop")){
		if(st->size == 0)
			printf("-1\n");
		else {
			printf("%d\n", st->value);
			st = st->next;
		}
	}	
}

