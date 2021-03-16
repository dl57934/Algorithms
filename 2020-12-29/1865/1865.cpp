#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void solve();

int main(){
	int testCase;
	scanf("%d", &testCase);

	for(int i = 0; i < testCase; i++)
		solve();
}

void solve(){
	vector<pair<int, int> > vc;
	int vertex[502] = { 0, }, map[502][502] = { 0, };
	int N, M, W;
	scanf("%d %d %d", &N, &M, &W);

	for(int i = 2; i <= N; i++)
		vertex[i] = INT_MAX;

	int start, end, cost; 
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &start, &end, &cost);
		if(map[start][end] == 0){
			vc.push_back(make_pair(start, end));
			vc.push_back(make_pair(end, start));
			map[start][end] =  cost;
			map[end][start] =  cost;
		}else{
			map[start][end] = min(map[start][end], cost);
			map[end][start] = map[start][end];
		}
	}

	for(int i = 0; i < W; i++){
		scanf("%d %d %d", &start, &end, &cost);
		if(map[start][end] == 0){
			vc.push_back(make_pair(start, end));
			map[start][end] = cost * -1;
		}else{
			map[start][end] = min(cost * -1, map[start][end]);
		}
	}

	for(int i = 1; i <= N; i++){
		for(auto now : vc){
			int start = now.first, end = now.second;
			if(vertex[start] == INT_MAX) continue;
			if(vertex[end] > map[start][end] + vertex[start])
				vertex[end] = map[start][end] + vertex[start];
		}
	}

	for(auto now : vc){
		int start = now.first, end = now.second;
		if(vertex[end] > vertex[start] + map[start][end]){
			printf("YES\n");
			return;
		}
	}

	if(vertex[1] < 0)
		printf("YES\n");
	else
		printf("NO\n");
}