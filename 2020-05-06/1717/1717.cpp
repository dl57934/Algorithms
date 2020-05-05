#include <cstdio>

int m, n;
int parent[1000002], rank[1000002];

void input();
void init();
void merge(int a, int b);
int find(int u);

int main(){
	init();
	input();
}

void input(){
	scanf("%d %d", &m, &n);
	int order, a, b;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &order, &a, &b);
		if( order == 1){
			if(find(a) == find(b))
				printf("yes\n");
			else 
				printf("no\n");
		}else{
			merge(a, b);
		}
	}
}

void init(){
	for(int i = 1; i <= 1000002; i++)
		parent[i] = i;
}

void merge(int a, int b){
	a = find(a), b = find(b);

	if( a == b ) return;

	if(rank[a] > rank[b]){
		int temp = a;
		a = b;
		b = temp;
	} 

	parent[a] = b;
	if(rank[a] == rank[b])
		rank[b]++;
}

int find(int u){
	if(parent[u] == u)
		return u;

	return parent[u] = find(parent[u]);
}