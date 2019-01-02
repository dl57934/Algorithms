#include <stdio.h>
#include <string.h>

#define PUSH "push"
#define POP "pop"
#define SIZE "size"
#define EMPTY "empty"
#define TOP "top"

int arr[10005] = {0,};

void push(int number);
int pop();
int size();
int empty();
int top();
void printResult(int n);
 
int main(N){
	char method[10];
	int input;

	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%s", method);
		if(!strcmp(method, PUSH)){
			scanf("%d", &input);
			push(input);
		}
		else if(!strcmp(method, POP))
			printResult(pop());

		else if(!strcmp(method, SIZE))
			printResult(size());
		
		else if(!strcmp(method, EMPTY))
			printResult(empty());
		
		else if(!strcmp(method, TOP))
			printResult(top());
	}
	return 0;
}

int ix = -1; 

void printResult(int n){
	printf("%d\n", n);
}

void push(int number){
	ix++;
	arr[ix] = number;
}

int pop(){
	int value;
	if(ix < 0){
		value = -1;
	}else{
		value = arr[ix];
		ix--;
	}

	return value;
}

int size(){
	return ix+1;
}

int empty(){
	if(ix < 0)
		return 1;
	return 0;
}

int top(){
	if(ix < 0)
		return -1;
	return arr[ix];
}