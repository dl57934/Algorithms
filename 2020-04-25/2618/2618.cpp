#include <cstdio>
#include <>

int N, W;
int map[1003][1003];
int dp[1003][1003];

void input();

int main(){

}

void input(){
	scanf("%d %d", &N, &W);

	for(int y = 1; y <= N; y++)
		for(int x = 1; x <= N; x++)
			map[y][x] = y+x-2;

	int start, end;
	for(int i = 0; i < W; i++)
		scanf("%d %d", &start, &end);
	
}	