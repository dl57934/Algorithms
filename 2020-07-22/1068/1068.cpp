#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> road[52];
int check[52];
int N;
int input(){
	int parent, start, stop;
	scanf("%d", &N);

	for(int leaf = 0; leaf < N; leaf++){
		scanf("%d", &parent);
		if(parent == -1)
			start = leaf;
		else
			road[parent].push_back(leaf);
	}
	scanf("%d", &stop);
	road[stop].clear();
	check[stop] = 1;
	return start;
}

void bfs(int start){
	queue<int> qu;
	int count = 0;
	qu.push(start);

	while(!qu.empty()){
		int now = qu.front();
		
		qu.pop();
		if(check[now] == 1)
			continue;	
		if(road[now].size() == 1 && check[road[now][0]] == 1)
			count++;
		else{
			for(auto next : road[now]){
				if(check[next] == 0){
					qu.push(next);
					if(road[next].size() == 0){
						count++;
					}

				}
			}	
		}
	}

	printf("%d", count);
}

int main(){
	bfs(input());
}