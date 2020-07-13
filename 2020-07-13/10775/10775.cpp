#include <cstdio>
int G, P;
int parent[100002];
int order[100002];

int find(int a);
void merge(int a, int b);
void input();

int main(){
	input();
	for(int plane = 1; plane <= P; plane++){
		int gate = find(order[plane]);
		if(gate != 0){
			merge(gate-1, gate);
		}else{
			printf("%d", plane-1);
			return 0;
		}
	}
	printf("%d", P);
}

void input(){
	scanf("%d%d", &G, &P);

	for(int i = 1; i <= G; i++)
		parent[i] = i;

	for(int i = 1; i <= P; i++){
		
		scanf("%d", &order[i]);
	}
}

int find(int a){
	if(parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b){
	a = find(a), b = find(b);
	if( a == b)
		return ;
	parent[b] = a;
}