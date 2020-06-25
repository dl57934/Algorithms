#include <cstdio>
#include <stdlib.h>
int company[200003];
int distance[200002];
int find(int company);
void merge(int company1, int company2);
void init();
void input();

int main(){
	input();
}

void input(){
	int testCase, companyNumber, company1, company2;
	char order;
	scanf("%d", &testCase);

	for(int i = 0; i < testCase; i++){
		init();
		scanf("%d", &companyNumber);
		while(scanf(" %c", &order) ){
			if(order == 'O')break;
			if(order == 'E'){
				scanf("%d", &company1);
				find(company1);
				printf("%d\n", distance[company1]);
			}else{
				scanf("%d %d", &company1, &company2);
				merge(company1, company2);
			}
		}
	}
}

int find(int companyName){
	if (companyName == company[companyName])
		return companyName;	
	int dis = find(company[companyName]);
		
	distance[companyName]+=distance[company[companyName]];
	return  company[companyName] = dis;
}

void merge(int company1, int company2){
	int dis = abs(company1-company2) % 1000;
	
	company[company1] = company2;
	distance[company1] = dis;
}

void init(){
	for(int i = 1; i <= 20000; i++){
		company[i] = i;
		distance[i] = 0;
	}
}