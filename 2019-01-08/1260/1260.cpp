#include <cstdio>
#include <list>

using namespace std;



list <int>li[1002];
int marked={0,};

void init(int N);
void addEdge(int start, int end);

int main(){
	int N, M, V;
	int point1, point2;
	scanf("%d %d %d", &N, &M, &V);
	init(N);
	for(int i = 0; i < M; i++){
		scanf("%d %d",&point1, &point2);
		addEdge(point1, point2);
	}
}

void init(int N){
	for(int i = 1; i <= N; i++)
		li[i].push_back(i);
}

void addEdge(int start, int end){
	int isFind = find(li[start].begin(), li[start].end(), end)
		if(isFind == end)
			li[start].push_back(end);
	isFind = find(li[end].begin(), li[end].end(), start);		
		if(isFind == start)
			li[end].push_back(start);
}