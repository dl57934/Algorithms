#include <cstdio>
#include <stdlib.h>

using namespace std;

int parent[20005];
int distances[200005];
int T, N;
void input();
void init();
void merge(int a, int b);
int find(int a);

int main(){
	input();
}

void input(){
	char order;
	int company1 , company2;
	scanf("%d", &T);

	for(int cs = 0; cs < T; cs++){
		scanf("%d", &N);
		init();
		while(scanf(" %c", &order)){
			if(order == 'O')
				break ;
			if(order == 'E'){
				scanf("%d", &company1);
				find(company1);
				printf("%d\n", distances[company1]);
			}else{
				scanf("%d %d", &company1, &company2);
				merge(company1, company2);
			}
		}
	}
}

void init(){
	for(int i = 1; i <= N; i++){
		parent[i] = i;
		distances[i] = 0;
	}
}

void merge(int a, int b){
	parent[a] = b;
	distances[a] = abs(a-b) % 1000;
}

int find(int a){
	if(a == parent[a])
		return a;

	int tmp = find(parent[a]);
	distances[a] += distances[parent[a]];
	parent[a] = tmp;
	return tmp;
}