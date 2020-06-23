#include <cstdio>

int find(int a);
void merge(int a, int b);
int rank[202];
int parent[202];
int map[202][202];
int N, M;

void init();

int main(){
	scanf("%d %d", &N, &M);
	init();

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%d", &map[i][j]);
			if(i < j && map[i][j] == 1){
				merge(i, j);
			}
		}
	}
	int point, anotherPoint;
	scanf("%d", &point);
	for(int i = 1; i < M; i++){
		scanf("%d", &anotherPoint);
		if(find(point) != find(anotherPoint)){
			printf("NO");
			return 0;
		}
		point = anotherPoint;
	}
	printf("YES");
}

void init(){
	for(int i = 1; i <= 200; i++){
		parent[i] = i;
	}
}

int find(int a){
	if(a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b){
	a = find(a), b = find(b);

	if(rank[a] > rank[b]){
		int temp = a;
		a = b;
		b = temp;
	}

	parent[a] = b;

	if(rank[a] == rank[b]) rank[b] ++;

}