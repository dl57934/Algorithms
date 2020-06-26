#include <cstdio>
#include <stdlib.h>

int parent[20004];
int distances[20004];

void input();
void init(int company);
int find(int company);
void merge(int company1, int company2);

int main(){
	input();
}

void input(){
	int companyNumber, testCase;
	int companyA, companyB;
	char order;
	scanf("%d", &testCase);
	for(int cs = 0; cs < testCase; cs++){
		scanf("%d", &companyNumber);
		init(companyNumber);
		while(scanf("%c", &order)){
			if(order == 'O')
				return;
			else if(order == 'E'){
				scanf("%d", &companyA);
				find(companyA);
				printf("%d\n", distances[companyA]);
			}else if(order == 'I'){
				scanf("%d %d", &companyA, &companyB);
				merge(companyA, companyB);
			}
		}
	}
}

void init(int company){
	for(int i = 1; i <= company; i++){
		parent[i] = i;
		distances[i] = 0;
	}
}

int find(int company){
	if(company == parent[company])
		return company;
	
	int dis = find(parent[company]);
	distances[company]+=distances[parent[company]];
	printf("test %d %d\n", distances[parent[company]], parent[company]);
	return parent[company] = dis;
}

void merge(int company1, int company2){
	if (company1 == company2)
		return ;
	parent[company1] = company2;
	distances[company1] = abs(company1 - company2) % 1000;
}