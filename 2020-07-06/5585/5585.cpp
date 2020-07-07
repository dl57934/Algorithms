#include <cstdio>

void minus(int base);
int num = 0, cost;
int main(){
	scanf("%d", &cost);
	cost = 1000-cost;
	minus(500);
	minus(100);
	minus(50);
	minus(10);
	minus(5);
	minus(1);
	printf("%d", num);
}

void minus(int base){
	if(cost / base){
		num+=cost / base;
		cost -= cost / base * base;
	}
}