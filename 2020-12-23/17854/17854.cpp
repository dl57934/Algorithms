#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack[1002][10002];
int N, K;
vector<pair<int, int > > vc;

void getKnapsack();

int main(){
	
	int importance, needTime;
	scanf("%d %d", &N ,&K) ;
	vc.push_back(make_pair(0, 0));
	for(int i = 1; i <= K; i++){
		scanf("%d %d", &importance, &needTime);
		vc.push_back(make_pair(importance, needTime));
	}

	getKnapsack();

	printf("%d", knapsack[K][N]);
}

void getKnapsack(){
	for(int y = 1; y <= K; y++){
		for(int x = 1; x <= N; x++){
			if(vc[y].second > x){
				knapsack[y][x] = knapsack[y-1][x];
			}else{
				knapsack[y][x] = max(knapsack[y-1][x], vc[y].first + knapsack[y-1][x - vc[y].second]);
			}
		}
	}
}