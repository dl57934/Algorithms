#include <cstdio>
#include <queue>

using namespace std;

int moveFloor[2];
queue <pair<int, int> > floor;
int check[1000003];
int F, S, G, U, D;

void input();
void bfs();

int main(){
	input();
	bfs();
}

void input(){
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	floor.push(make_pair(S, 0));
	moveFloor[0] = U;
	moveFloor[1] = -1 * D;
}

void bfs(){
	while(!floor.empty()){
		int now = floor.front().first;
		int distance = floor.front().second;
		floor.pop();

		if(now == G){
			printf("%d", distance);
			return ;
		}

		for(int i = 0; i < 2; i++){
			int nextFloor = now + moveFloor[i];
			if(nextFloor >= 1 && nextFloor <= F && check[nextFloor] == 0){
				check[nextFloor] = 1;
				floor.push(make_pair(nextFloor, distance+1));
			}
		}
	}

	printf("use the stairs");
}