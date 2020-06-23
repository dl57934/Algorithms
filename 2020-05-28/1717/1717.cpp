#include <cstdio>

const int SAME = 1;
int n, m;
int arr[1000002];
void set();
void input();
int find(int a);
void merge(int a, int b);
int main(){
	input();
}

void input(){
	scanf("%d %d", &n, &m);
	set();
	int order = 0, a = 0, b = 0;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &order, &a, &b);
		if(order == 1){
			if(find(a) == find(b)){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else{
			merge(a, b);
		}
	}
}

void set(){
	for(int i = 1; i <= n; i++)
		arr[i] = i;
}


void merge(int a, int b){
	int aParent = find(a);
	int bParent = find(b);

	if(aParent == bParent)
		return;

	arr[aParent] = bParent;
}

int find(int a){
	if(arr[a] == a){
		return a;
	}
	return arr[a] = find(arr[a]);
}
