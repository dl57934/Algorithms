#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> vc[102];
int vertex[102];
int N, M;
void input();
void bfs(int start);

int main(){
	int per = 0, INF = 98765432;
	input();
	for(int person = 1; person <= N; person++){
		bfs(person);
	}

	for(int person = 1; person <= N; person++){
		if( INF > vertex[person]){
			per = person;
			INF = vertex[person];
		}
	}
	printf("%d", per);
}


void input(){
	int me, another;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d %d", &me, &another);
		vc[me].push_back(another);
		vc[another].push_back(me);
	}
}

void bfs(int start){
	queue <pair<int, int> > qu;
	int check[102] = {0, };
	qu.push(make_pair(0, start));
	check[start] = 1;
	while(!qu.empty()){
		pair<int, int> now = qu.front();
		int cost = now.first;
		int nowPoint = now.second;
		vertex[start] += cost;
		qu.pop();
		for(auto next : vc[nowPoint]){
			if(check[next] == 0){
				qu.push(make_pair(cost+1, next));	
				check[next] = 1;
			}
		}
	}
} 