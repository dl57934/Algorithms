#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, int> > qu;
int floor[1000003];
int F, S, G, U, D;


void bfs();
void input();
int main(){
	input();
	bfs();
}

void input(){
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
}

void bfs(){
	qu.push(make_pair(S, 0));
	floor[S] = 1;
	int move[2];
	move[0] = U;
	move[1] = -1 * D;

	while(!qu.empty()){
		int nowFloor = qu.front().first;
		int distance = qu.front().second;
		
		qu.pop();
		if(nowFloor == G){
			printf("%d", distance);
			return ;
		}
		for(int i = 0; i < 2; i++){
			int nextFloor = nowFloor + move[i];
			if(nextFloor >= 1 && nextFloor<=F && floor[nextFloor] == 0){
				qu.push(make_pair(nextFloor, distance+1));
				floor[nextFloor] = 1;
			}
		}
	}
	printf("use the stairs");
}