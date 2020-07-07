#include <cstdio>
#include <vector>

using namespace std;

vector<int> airplane;
int parent[100002];
int G, P;
void input();
void init();
int find(int a);
void merge(int a, int b);

int main(){
	input();
	int num = 0;
	for(auto plane:airplane){
		int root = find(plane);
		if(root == 0){
			printf("%d", num);
			return 0;
		}else{
			merge(root-1, root);
		}
		num++;
	}

	printf("%d", num);
}



void input(){
	int plane;
	scanf("%d %d", &G, &P);
	init();

	for(int i = 0; i < P; i++){
		scanf("%d", &plane);
		airplane.push_back(plane);
	}
}

void init(){
	for(int i = 1; i <= G; i++)
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
		return;
	}

	parent[b] = a;
}