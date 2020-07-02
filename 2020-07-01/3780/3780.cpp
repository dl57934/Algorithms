#include <cstdio>
#include <stdlib.h>
int parent[20002];
int distances[200002];

void init();
void input();
void merge(int company, int center);
int find(int company);

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
		distances[i] = 0;
	}
}

void input(){
	int vertex;
	char order;
	scanf("%d", &vertex);
	int company1, company2;

	while(1){
		scanf(" %c", &order);
		if(order == 'E'){
			scanf("%d", &company1);
			find(company1);
			printf("%d\n", distances[company1]);
		}else if(order == 'I'){
			scanf("%d %d", &company1, &company2);
			merge(company1, company2);
		}else {
			break;
		}
	}
}

void merge(int company, int center){
	
	parent[company] = center;

	distances[company] = abs(company-center) % 1000;
}

int find(int company){
	if(company == parent[company])
		return company;
	
	int previousCompany = find(parent[company]);
	distances[company] += distances[parent[company]];
	parent[company] = previousCompany;
	
	return previousCompany;
}