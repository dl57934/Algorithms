#include <cstdio>
#include <queue>

using namespace std;

int distances[100002];
queue <pair<int, int> >qu;

void bfs();

int N, K;

int main(){
	scanf("%d %d", &N, &K);
	bfs();
}


void bfs(){
	qu.push(make_pair(N, 0));
	while(!qu.empty()){
		pair<int, int> point = qu.front();
		int nowValue = point.first;
		int nowTime = point.second;
		qu.pop();
		
		if(nowValue == K){
			printf("%d", nowTime);
			break;
		}
		distances[nowValue] = 1;

		if(nowValue * 2 <= 100000 && !distances[nowValue * 2])
			qu.push(make_pair(nowValue * 2, nowTime+1));
		if(nowValue +1 <= 100000 && !distances[nowValue + 1])
			qu.push(make_pair(nowValue + 1, nowTime+1));
		if(nowValue - 1<= 100000 && !distances[nowValue - 1] && nowValue >= 0)
			qu.push(make_pair(nowValue - 1, nowTime+1));
	}
}


#include <cstdio>
#include <queue>

using namespace std;

int N, K;
queue <pair<int, int> >qu;
int distances[100002];

void bfs();

int main(){
	scanf("%d %d", &N, &K);
	bfs();
}



#include <cstdio>
#include <queue>

using namespace std;

int distances[100002];
queue <pair<int, int> >qu;

void bfs();

int N, K;

int main(){
	scanf("%d %d", &N, &K);
	bfs();
}


