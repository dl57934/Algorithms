#include <cstdio>

int level[1000002];
int parent[1000002];
int n, m;

int find(int a);
void merge(int a, int b);
void init();

int main(){
	int type, set1, set2;

	scanf("%d %d", &n, &m);
	init();

	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &type, &set1, &set2);
		if(type == 0){
			merge(set1, set2);
		}else{
			if(find(set1) == find(set2)){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}

}

void init(){
	for(int i = 1; i <= n; i++)
		parent[i] = i;
}

int find(int a){
	if(a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b){
	a = find(a), b = find(b);

	if(level[a] > level[b]){
		int temp = a;
		a = b;
		b = temp;
	}

	parent[a] = b;

	if(level[a] == level[b])
		level[b]++;
}