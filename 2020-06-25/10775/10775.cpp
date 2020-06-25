#include <cstdio>
#include <vector>

using namespace std;

int parent[100002];
vector<int> orders;

void init();
void input();
int find(int port);
void merge(int leftPort, int rightPort);

int main(){
	init();
	input();
	int answer = 0;
	for(auto order : orders){
		int docker = find(order);
		if(docker == 0){
			break;
		}else{
			merge(docker-1, docker);
			answer+=1;
		}
	}
	printf("%d", answer);
}

void init(){
	for(int i = 1; i <= 100000; i++)
		parent[i] = i;
}

void input(){
	int G, P, gate;
	scanf("%d%d", &G, &P);

	for(int i = 0; i < P; i++){
		scanf("%d", &gate);
		orders.push_back(gate);
	}
}

void merge(int leftPort, int rightPort){
	leftPort = find(leftPort), rightPort = find(rightPort);

	if (leftPort == rightPort) return;

	parent[rightPort] = leftPort;
}

int find(int port){
	if(parent[port] == port)
		return port;
	return parent[port] = find(parent[port]);
}