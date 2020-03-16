#include <cstdio>
#include <queue>
#include <utility>

int checked[3000000];

using namespace std;

queue <pair<int, int> > qu; //second, value

int N, K;

void bfs();

int main(){
	scanf("%d %d", &N, &K);
	qu.push(make_pair(0, N));
	bfs();
}

void bfs(){

	while(!qu.empty()){
		pair<int, int> point = qu.front();
		qu.pop();
		if(point.second == K){
			printf("%d", point.first);
			break;
		}
		if(!checked[point.second*2] && point.second*2 <= 100000){
			qu.push(make_pair(point.first+1, point.second*2));
			checked[point.second*2] = 1;
		}
		if(!checked[point.second+1] && point.second+1 <= 100000){
			qu.push(make_pair(point.first+1, point.second+1));
			checked[point.second+1] = 1;		
		}
		if(!checked[point.second-1] && point.second-1 >= 0){
			qu.push(make_pair(point.first+1, point.second-1));
			checked[point.second-1] = 1;		
		}
	}
}