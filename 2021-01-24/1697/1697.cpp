#include <cstdio>
#include <queue>

using namespace std;

int visited[1000020];


int main(){
	int N, K;

	scanf("%d %d", &N, &K);

	queue <pair<int, int> > qu;

	qu.push(make_pair(N, 0));
	visited[N] = 1;
	while(!qu.empty()){
		pair<int, int> now = qu.front();

		if(now.first == K){
			printf("%d", now.second);
			return 0;
		}
		qu.pop();

		if(now.first + 1 <= 100000 && visited[now.first + 1] == 0){
			visited[now.first+1] = 1;
			qu.push(make_pair(now.first+1, now.second + 1));
		}

		if(now.first*2 <= 100000 && visited[now.first * 2] == 0){
			visited[now.first*2] = 1;
			qu.push(make_pair(now.first*2, now.second + 1));
		}

		if( now.first > 0){
			if(visited[now.first - 1] == 0){
				visited[now.first-1] = 1;
				qu.push(make_pair(now.first-1, now.second + 1));
			}
		}

	}
}