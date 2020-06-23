#include <cstdio>

int n, m;

int parent[1000000], rank[100000];

void init();
void merge(int a, int b);
int find(int num);

int main(){
	scanf("%d %d", &n, &m);
	init();
	int a, b, c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a == 0){
			merge(b, c);
		}else{
			if(find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}

void init(){
	for(int i = 1; i <= n; i++)
		parent[i] = i;
}

int find(int num){
	if(num == parent[num])
		return num;
	return parent[num] = find(parent[num]);
}

void merge(int a, int b){
	a = find(a), b = find(b);

	if(a == b)
		return ;

	if(rank[a] > rank[b]){
		int temp = a;
		a = b;
		b = temp;	
	}

	parent[a] = b;

	if(rank[a] == rank[b])
		rank[b]++;

}