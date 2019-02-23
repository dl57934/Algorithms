#include <cstdio>
#include <queue>

using namespace std;

int xpos[4] = {0, 1, 0, -1};
int ypos[4] = {1, 0, -1, 0};
int M, N;
int tomatos=0;
int nonRipeTomato = 0;
int notTomato = 0;
queue <pair<int, int> >qu; 
queue <pair<int, int> > startqu;
int map[1002][1002];

void input();
void findRipeTomato();
int bfs();

int main(){
	scanf("%d %d", &M, &N);
	input();
	findRipeTomato();
}

void input(){
	for(int j = 1; j<=N; j++)
		for(int i = 1; i <=M; i++){
			scanf("%d", &map[j][i]);
			if(map[j][i]==-1)
				notTomato+=1;
			if(map[j][i]!=-1 && map[j][i]!=1)
				nonRipeTomato+=1;
		}
}

void findRipeTomato(){
	for(int j = 1; j<=N; j++)
		for(int i = 1; i <=M; i++)
			if(map[j][i]==1){
				startqu.push(make_pair(j, i));
			}
	if(nonRipeTomato == 0)
		printf("0");		
	else 
		printf("%d\n", bfs());			
}

int bfs(){
	int result = 0;
	
	while(!startqu.empty()){
		pair<int, int> xy = startqu.front();
		startqu.pop();
		tomatos +=1;
		for(int i = 0; i < 4; i++){
			int ay = xy.first + ypos[i];
			int ax = xy.second + xpos[i];		
			if(ax>=1 && ay>=1 && ax <= M && ay <= N && map[ay][ax]==0){
				map[ay][ax]=1;
				qu.push(make_pair(ay, ax));
				}
			}
			if(startqu.empty()&& !qu.empty()){
				startqu = qu;	
				result+=1;
				while(!qu.empty())
					qu.pop();
			}
		}
		
		int allTomato = M*N-notTomato;
		if(allTomato == tomatos)
			return result;
		else 
			return -1;
}