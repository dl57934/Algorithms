#include <cstdio>

int parent[204];
int rank[204];
int road[1003];
int N, M;
void input();

int find(int u);
void merge(int u, int v);

int main(){
	for(int i = 1; i <= 200; i++)
		parent[i] = i;
	input();
	for(int start = 1; start <= N; start++){
		printf("parent %d rank %d\n", parent[start], rank[start]);
	}

	for(int start = 1; start < M; start++){
		if(find(road[start]) != find(road[start+1])){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
		
}

void input(){
	scanf("%d", &N);
	scanf("%d", &M);
	int value;
	for(int start = 1; start <= N; start++){
		for(int end = 1; end <= N; end++){
			scanf("%d", &value);
			if(value == 1){
				merge(start, end);
			}
		}
	}

	for(int i  = 1; i <= M; i++ )
		scanf("%d", &road[i]);
}

int find(int u){
	if(u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

void merge(int u, int v){
	u = find(u);
	v = find(v);
	if( u == v )return;

	if(rank[u] > rank[v]){
		int temp = u;
		u = v;
		v = temp;
	}

	parent[u] = v; 

	if(rank[u] == rank[v]) rank[u]++;
}