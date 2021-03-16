#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void solve();
void torpologySort(vector<int> vc[], vector<int> ingreed[]);

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		solve();		
	}

}

int dp[1002] = {0, };
int value[1002] = {0, };
int N, K, W;
void solve(){
	vector<int> vc[1002], ingreed[1002];
	memset(dp, -1, sizeof(dp));
	memset(value, 0, sizeof(value));

	int start, end;
	scanf("%d %d", &N, &K);
	
	for(int i = 1; i <= N; i++)
		scanf("%d", &value[i]);
	

	for(int i = 0; i < K; i++){
		scanf("%d %d", &start, &end);
		vc[start].push_back(end);
		ingreed[end].push_back(start);
	}

	scanf("%d", &W);

	torpologySort(vc, ingreed);

	printf("%d\n", dp[W]);
}

void torpologySort(vector<int> vc[], vector<int> ingreed[]){
	queue<int> qu;
	for(int i = 1; i <= N; i++){
		if(ingreed[i].size() == 0)
			qu.push(i);
	}

	while(!qu.empty()){
		int now = qu.front();
		qu.pop();
		dp[now] = max(dp[now], value[now]);
		for(auto next : vc[now]){
			dp[next] = max(dp[next], dp[now] + value[next]);
			ingreed[next].pop_back();
			if(ingreed[next].size() == 0)
				qu.push(next);
		}
	}
}