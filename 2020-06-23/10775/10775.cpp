#include <cstdio>
#include <vector>

using namespace std;

vector<int> orders;
int gates[100002];
int G, gate, P;
void input();
void init();
int find(int a);
void merge(int a, int b);

int main(){
	init();
	input();
	int answer = 0;
	for(auto order: orders){
		int docker = find(order);
		if(docker !=0){
			answer++;
			merge(docker, docker-1);
		}else{
			break;
		}
	}
	printf("%d", answer);
}

void init(){
	for(int i = 1; i <= 100000; i++)
		gates[i] = i;
}

void input(){
	
	scanf("%d %d", &G, &P);	
	for(int plane = 1; plane <= P; plane++){
		scanf("%d", &gate);
		orders.push_back(gate);
	}
}

int find(int a){
	if(a == gates[a])
		return a;
	return gates[a] = find(gates[a]);
}

void merge(int a, int b){
	a = find(a), b = find(b);
	if(a == b)return;
	gates[a] = b;
}