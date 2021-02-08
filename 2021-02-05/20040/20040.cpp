#include <cstdio>

typedef struct DisjointSet{
	int parent[500002];
	void set(int N){
		for(int i = 0; i < N; i++){
			parent[i] = i;
		}
	}

	int find(int a){
		if(parent[a] == a){
			return a;
		}
		return parent[a] = find(parent[a]);
	}

	int merge(int a, int b){
		a = find(a), b = find(b);

		if(a == b)
			return 1;

		parent[a] = b;
		return 0;
	}
}DisjointSet;

int main(){
	int N, M;
	int a, b;
	DisjointSet disjoint;
	scanf("%d %d", &N, &M);
	disjoint.set(N);
	int isFindAnswer = 0, result = 0;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &a, &b);
		int isCycle = disjoint.merge(a, b);
		if(isCycle && !isFindAnswer){
			result = i + 1;
			isFindAnswer = 1;
		}
	}

	printf("%d", result);

	
}