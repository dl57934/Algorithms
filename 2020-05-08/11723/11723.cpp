#include <cstdio>
#include <string.h>

int mask = 0;
int orderNumber;

void add(int num);
void remove(int num);
void check(int num);
void toggle(int num);
void all();
void empty();
int isSameOrder(char order1[], char order2[]);

int main(){
	char order[30];
	int inputNum = 0;
	scanf("%d", &orderNumber);
	for(int i = 0; i < orderNumber; i++){
		scanf(" %s", &order);
		if(isSameOrder(order, "add")){
			scanf("%d", &inputNum);
			add(inputNum-1);		
		}else if(isSameOrder(order, "remove")){
			scanf("%d", &inputNum);
			remove(inputNum-1);		
		}else if(isSameOrder(order, "check")){
			scanf("%d", &inputNum);
			check(inputNum-1);		
		}else if(isSameOrder(order, "toggle")){
			scanf("%d", &inputNum);
			toggle(inputNum-1);		
		}else if(isSameOrder(order, "all")){
			all();		
		}else if(isSameOrder(order, "empty")){
			empty();		
		}
	}
}

void add(int num){
	mask |= (1 << num);
}

void remove(int num){
	mask -= (1 << num);
}

void check(int num){
	if( (mask & (1 << num)) )
		printf("1\n");	
	else
		printf("0\n");	
}

void toggle(int num){
	mask ^= (1 << num);
}

void all(){
	mask = (1 << 20)-1;
}

void empty(){
	mask = 0;
}

int isSameOrder(char order1[], char order2[]){
	if(!strcmp(order1, order2))
		return 1;
	return 0;
}