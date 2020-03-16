#include <cstdio>
#include <queue>
#include <utility>

int checked[3000000];

using namespace std;

queue <pair<int, int> > qu; //second, value

int N, K;
int method = 0;

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
		checked[point.second] = 1;
		if(point.second == K){
			method+=1;
			while(!qu.empty()){
				pair<int, int> destination = qu.front();
				qu.pop();
				if(destination.second == K && point.first == destination.first){
					method+=1;
				}
			}
			printf("%d\n%d", point.first, method);
			break;
		}
		if(!checked[point.second*2] && point.second*2 <= 100000){
			qu.push(make_pair(point.first+1, point.second*2));
			 
		}
		if(!checked[point.second+1] && point.second+1 <= 100000){
			qu.push(make_pair(point.first+1, point.second+1));
				
		}
		if(!checked[point.second-1] && point.second-1 >= 0){
			qu.push(make_pair(point.first+1, point.second-1));
					
		}
	}
}