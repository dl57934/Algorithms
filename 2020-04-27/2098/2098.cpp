#include <cstdio>

int N;

int memo[19][70000], map[19][19];

void input();
int TSP(int current, int next);
int min = 987654321;

int main(){
	input();
	printf("%d", TSP(0, 0));
	
}

void input(){
	scanf("%d", &N);
	for(int yPos = 0; yPos < N; yPos++)
		for(int xPos = 0; xPos < N; xPos++)
			scanf("%d", &map[yPos][xPos]);
}

int TSP(int current, int next){
	next |= (1 << current);

	if( next ==  (1 << N) - 1){
		if(map[current][0] > 0)
			return map[current][0];			
		else 
			return 987654321;
	}

	if(memo[current][next] > 0)
		return memo[current][next]; 

	int ret = 987654321;

	for(int i = 0; i < N; i++){
		if(map[current][i] > 0 && (next & (1 << i))==0){
			int temp = TSP(i, next) + map[current][i];
			if(ret > temp)
				ret = temp;
		}
	}
	memo[current][next] = ret;
	return ret;
}