#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int map[110][110][110];
//높이 세로 가로

int xpos[6] = {0, 1, 0, -1, 0, 0};
int ypos[6] = {1, 0, -1, 0, 0, 0};
int hpos[6] = {0, 0, 0, 0, 1, -1};
struct location{
	int x, y, h;
};

int M, N, H; //M 가로 N 세로 H 높이
queue <location> startLocationQu;
queue <location> middleLocationSaveQu;
void input();
int notTomato = 0;
int ripetomato = 0;
int bfs();

int main(){
	scanf("%d%d%d", &M, &N, &H);
	input();
	printf("%d", bfs());
}

void input(){
	for(int h=0; h<H; h++)
        for(int n=0; n<N; n++)
            for(int m=0; m<M; m++){
				scanf("%d", &map[h][n][m]);
			if(map[h][n][m] == 1){
					location p = {m, n, h};
					startLocationQu.push(p);
					ripetomato +=1;
				}
			else if(map[h][n][m] == -1)
					notTomato+=1;
	}
}

int bfs(){
	int step=0;
	int visit = 0;
	while(!startLocationQu.empty()){
		location startlocation = startLocationQu.front();
		startLocationQu.pop();
		for(int i =0; i < 6; i++){
			int ax = startlocation.x + xpos[i];
			int ay = startlocation.y + ypos[i];
			int ah = startlocation.h + hpos[i];
			if(ax>=0 && ax<M  && ay>=0 && ay<N && ah>=0 && ah<H){
				if(map[ah][ay][ax] == 0 ){
					location p = {ax, ay, ah};
					middleLocationSaveQu.push(p);
					map[ah][ay][ax]=1;
					visit+=1;
				}
			}
		}
		if(startLocationQu.empty() && !middleLocationSaveQu.empty()){
			startLocationQu = middleLocationSaveQu;
			step+=1;
			while(!middleLocationSaveQu.empty())
				middleLocationSaveQu.pop();
		}
	}
	if (visit == 0)
		return 0;
	else if( visit+notTomato+ripetomato != M*N*H)
		return -1;
	else
		return step;
}