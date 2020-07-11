#include <cstdio>
#include <queue>

using namespace std;

queue <pair<int, int> > qu;
int F, S, G, U, D;
int result;
int check[1000002];
int moveDistance[2];
void bfs();

int main(){
  scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
  moveDistance[0] = U;
  moveDistance[1] = -1 * D;

  bfs();
}

void bfs(){
	qu.push(make_pair(S, 0));

	while(!qu.empty()){
		pair<int, int> now = qu.front();
		qu.pop();
		if(G == now.first){
			printf("%d", now.second);
			return ;
		}

		for(int i = 0; i < 2; i++){
			int nextPoint = now.first + moveDistance[i];
			if(nextPoint >= 1 && nextPoint <= F && check[nextPoint] == 0){
				qu.push(make_pair(nextPoint, now.second+1));
				check[nextPoint] = 1;
			}
		}
	}
	printf("use the stairs");
}