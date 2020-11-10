#include <cstdio>
#include <string.h>

int M, mask;


void add(int x);
void remove(int x);
int check(int x);
void toggle(int x);
void all();
void empty();
bool isSameOrder(char order1[], char order2[]);

int main(){
	int number;
	char order[30];
	scanf("%d", &M);

	for(int i = 0; i < M; i++){
		scanf(" %s", &order);
		if(isSameOrder(order, "add")){
			scanf("%d", &number);
			add(number-1);
		}else if(isSameOrder(order, "remove")){
			scanf("%d", &number);
			remove(number-1);
		}else if(isSameOrder(order, "check")){
			scanf("%d", &number);
			printf("%d\n", check(number-1));
		}else if(isSameOrder(order, "toggle")){
			scanf("%d", &number);
			toggle(number-1);
		}else if(isSameOrder(order, "all")){
			all();			
		}else{
			empty();
		}
	}
}


void add(int x){
	printf("%d\n", (1 << x));
	printf("%d\n", ~(1 << x));
	mask |= (1 << x);
}

void remove(int x){
	printf("%d\n", ~(1 << x));
	mask &= ~(1 << x);
}

int check(int x){
	if((mask & (1 << x)) > 0 )
		return 1;
	else return 0;
}

void toggle(int x){
	mask ^= (1 << x);	
}

void all(){
	mask = (1 << 20) - 1;
}

void empty(){
	mask = 0;
}

bool isSameOrder(char order1[], char order2[]){
	if(strcmp(order1, order2) == 0)
		return true;
	return false;
}