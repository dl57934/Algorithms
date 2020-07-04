#include <cstdio>
#include <vector>

using namespace std;

vector<int> orders;
int parent[100004];
void input();
void init();
int find(int num);
void merge(int port1, int port2);

int main(){
	init();
	input();
	int result = 0; 
	for(auto order:orders){
		int rootPort = find(order);
		if(rootPort==0){
			printf("%d", result);
			return 0;
		}else{
			result++;
			merge(rootPort-1, rootPort);
		}
	}
	printf("%d", result);
}

void init(){
	for(int i = 1; i <= 100000; i++)
		parent[i] = i;
}

void input(){
	int G, P, port;
	scanf("%d %d", &G, &P);
	
	for(int plane = 1; plane <= P; plane++){
		scanf("%d", &port);
		orders.push_back(port);
	}
}


int find(int num){
	if(num == parent[num])
		return num;
	return parent[num] = find(parent[num]);
}

void merge(int port1, int port2){
	port1 = find(port1), port2 = find(port2);

	if(port1 == port2) 
		return;

	parent[port2] = port1;
}