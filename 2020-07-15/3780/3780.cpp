#include <cstdio>
#include <stdlib.h>
int parent[20002], vertex[20002];
int N;
void init();
void input();
int find(int a);
void merge(int another, int base);

int main(){
	int testCase;
	scanf("%d", &testCase);

	for(int cs = 0; cs < testCase; cs++){
		init();
		input();
	}
}

void init(){
	for(int i = 1; i <= 20000; i++){
		parent[i] = i;
		vertex[i] = 0;
	}
}

void input(){
	scanf("%d", &N);
	char order;
	int company1, company2;
	while(scanf(" %c", &order)){
		if(order == 'E'){
			scanf("%d", &company1);
			find(company1);
			printf("%d\n", vertex[company1]);
		}else if(order == 'I'){
			scanf("%d %d", &company1, &company2);
			merge(company1, company2);
		}else
			break;
	}
}

int find(int a){
	if(a == parent[a])
		return a;

 	int temp = find(parent[a]);
 	vertex[a] += vertex[parent[a]];
 	parent[a] = temp;
 	return temp;
}

void merge(int another, int base){
	int distance = abs(another - base) % 1000;
	parent[another] = base;
	vertex[another] = distance;
}

