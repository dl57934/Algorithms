#include <cstdio>
#include <string.h>

#define ll long long

int M;
ll bitMask;
char instruction[7];

int check(ll x);
void toggle(ll x);
void remove(ll x);
void add(ll x);
void all();
void empty();


int main(){
	scanf("%d", &M);
	ll number;
	for(int i = 0; i < M; i++){
		scanf(" %s", &instruction);
		if( !strcmp(instruction, "add")){
			scanf("%lld", &number);
			add(number-1);
		}else if(!strcmp(instruction, "check")){
			scanf("%lld", &number);
			printf("%d\n", check(number-1));
		}else if(!strcmp(instruction, "remove")){
			scanf("%lld", &number);
			remove(number-1);
		}else if(!strcmp(instruction, "toggle")){
			scanf("%lld", &number);
			toggle(number-1);
		}else if(!strcmp(instruction, "all")){
			all();
		}else if(!strcmp(instruction, "empty")){
			empty();
		}
	}
}


int check(ll x){
	if ((bitMask & (1 << x)))
		return 1;
	else return 0;
}

void toggle(ll x){
	bitMask ^= (1 << x);
}

void remove(ll x){
	bitMask -= (1 << x);
}

void add(ll x){
	bitMask |= (1 << x);
}

void all(){
	bitMask = (1 << 20) - 1;
}

void empty(){
	bitMask = 0;
}