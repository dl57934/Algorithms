#include <cstdio>
#include <vector>
#include <climits>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int N, M;
int map[52][52];
int check[15], values[15];
vector<pair<int, int> > chicken, home;
int minValue = INT_MAX;
void backTrack(int limit);

int main(){
	
	scanf("%d %d", &N, &M);

	int num;
	for(int y = 1; y<= N; y++){
		for(int x = 1; x<= N; x++){
			scanf("%d", &num);
			if(num == 1)
				home.push_back(make_pair(y, x));
			else if(num == 2)
				chicken.push_back(make_pair(y, x));
		}
	}

	backTrack(0);

	printf("%d", minValue);
}

void backTrack(int limit){
	if(limit == M){
		int weight[52][52] = {0, };
		for(auto hm : home){
			for(int i = 0; i < M; i++){
				if(weight[hm.first][hm.second] == 0)
					weight[hm.first][hm.second] = abs(hm.first - chicken[values[i]].first) + abs(hm.second-chicken[values[i]].second);
				else	
			 		weight[hm.first][hm.second] = min(abs(hm.first - chicken[values[i]].first) + abs(hm.second-chicken[values[i]].second), weight[hm.first][hm.second]);
			}
		}


		int subResult = 0;

		for(auto hm : home){
			subResult += weight[hm.first][hm.second];
		}

		if(subResult < minValue)
			minValue = subResult;
		return ;
	}

	
	for(int i = 1; i <= chicken.size(); i++){
		if(check[i] == 0 && values[limit-1] < i){
			check[i] = 1;
			values[limit] = i-1;
			backTrack(limit+1);
			check[i] = 0;
		}
	}
}