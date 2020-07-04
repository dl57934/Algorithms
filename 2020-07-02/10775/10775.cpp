#include <cstdio>
#include <vector>

using namespace std;

int parent[100002];
vector<int> order;
int find(int a);
void merge(int a, int b);
void init();
void input();


int main(){
	int result = 0;
	init();
	input();
	for(auto ord : order){
		int via = find(ord);
		if(via == 0){
			printf("%d", result);
			return 0;
		}else{
			result++;
			merge(via-1, via);
		}
	}
	printf("%d", result);
}

void input(){
	int G,P;
	int plane;
	scanf("%d %d", &G, &P);
	
	for(int i = 1; i <= P; i++){
		scanf("%d", &plane);
		order.push_back(plane);
	}
}

void init(){
	for(int i = 1; i <= 100000; i++)
		parent[i] = i;
}

int find(int a){
	if(parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b){
	a = find(a), b = find(b);

	if(a == b){
		return ;
	}

	parent[b] = a;
}