#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int map[300000];
int method = 0;
queue <pair<int, int> > qu;

int N, K;

void bfs();
int isValidPoint(int point);
int isDestinationPoint(int point);

int main(){
	scanf("%d %d", &N, &K);
	bfs();
}

void bfs(){
	qu.push(make_pair(0, N));
	map[N] = 1;

	while(!qu.empty()){
		pair<int, int> previousPoint = qu.front();
		qu.pop();
		
		if(isDestinationPoint(previousPoint.second)){
			printf("%d", previousPoint.first);
			break;
		}

		int movePoint[3];
		movePoint[0] = previousPoint.second * 2;
		movePoint[1] = previousPoint.second + 1;
		movePoint[2] = previousPoint.second - 1;
		
		if(isValidPoint(movePoint[0])){
			qu.push(make_pair(previousPoint.first+1, movePoint[0]));
			map[movePoint[0]] = 1;
		}
		if(isValidPoint(movePoint[1])){
			qu.push(make_pair(previousPoint.first+1, movePoint[1]));
			map[movePoint[1]] = 1;
		}
		if(isValidPoint(movePoint[2]) && movePoint[2] >= 0){
			qu.push(make_pair(previousPoint.first+1, movePoint[2]));
			map[movePoint[2]] = 1;
		}
	}
}


int isValidPoint(int point){
	if(point <= 100000 && !map[point])
		return 1;
	else return 0;
}

int isDestinationPoint(int point){
	if(K==point)
		return 1;
	else return 0;
}