#include <cstdio>
#include <vector>

using namespace std;
int parent[100002];
vector<int> order;
void input();

int find(int num){
	if(parent[num] == num)
		return num;
	return parent[num] = find(parent[num]);
}

void merge(int num1, int num2){
	num1 = find(num1), num2 = find(num2);

	if(num1 == num2)
		return;

	parent[num2] = num1;
}


int main(){
	input();
	int count = 0;
	for(auto ord : order){
		int port = find(ord);
		if(port == 0){
			printf("%d", count);
			return 0;
		}else{
			merge(port-1, port);
			count++;
		}
	}

	printf("%d", count);
}

void input(){
	int G, P, plane;
	scanf("%d %d", &G, &P);

	for(int i = 0; i < P; i++){
		scanf("%d", &plane);
		order.push_back(plane);
	}

	for(int i = 1; i <= G; i++)
		parent[i] = i;
}