#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1002];
int stateOfLine[1002];
int N, spendTime[1002];
int dp[1002];
void input();
void solve();
int main(){
	input();
	solve();
}

void input(){
	scanf("%d", &N);
	int nextOfHouse = 0;
	for(int i = 1; i <= N; i++){
		scanf("%d", &spendTime[i]);
		while(1){
			scanf("%d", &nextOfHouse);
			if(nextOfHouse==-1)
				break;
			else{
				graph[nextOfHouse].push_back(i);
				stateOfLine[i]++;
			}
		}
	}
}

void solve(){
	queue <int> qu;

	for(int i = 1; i <= N; i++){
		if(stateOfLine[i] == 0)
			qu.push(i);
	}

	while(!qu.empty()){
		int now = qu.front();

		dp[now] = max(dp[now], spendTime[now]);
		qu.pop();
		for(auto next : graph[now]){
			stateOfLine[next]--;

			dp[next] = max(dp[next], dp[now] + spendTime[next]);
			if(stateOfLine[next] == 0){
				qu.push(next);
			}
		}
	}

	for(int i = 1; i <= N; i++)	
		printf("%d\n", dp[i]);
}