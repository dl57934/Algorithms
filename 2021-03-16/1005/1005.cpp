#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;


void input();
void solve();

int N, K;
int spendTime[1002], linkOfState[1002], lastPoint;
vector<int> vc[1002];

int main(){
	int T;
	scanf("%d", &T);

	for(int testCase = 0; testCase < T; testCase++){
		input();
		solve();
	}
}

void input(){
	scanf("%d %d", &N, &K);
	
	for(int i = 1; i <= N; i++)
		scanf("%d", &spendTime[i]);
	int start, destination;
	for(int line = 0; line < K; line++){
		scanf("%d %d", &start, &destination);
		vc[start].push_back(destination);
		linkOfState[destination]++; 
	}

	scanf("%d", &lastPoint);
}	

void solve(){
	queue<int> qu;
	int dp[1002] = {0, }, lastIndex = 1;
	for(int i = 1; i <= N; i++){
		if(linkOfState[i] == 0)  qu.push(i);
	}

	while(!qu.empty()){
		int now = qu.front();
		qu.pop();	
		dp[now] = max(dp[now] ,spendTime[now]);

		for(auto next : vc[now]){
			linkOfState[next]--;
			if(dp[next] < dp[now] + spendTime[next])
				dp[next] = dp[now] + spendTime[next];
			if(linkOfState[next] == 0){
				
				qu.push(next);
			}
		}
	}

	printf("%d\n", dp[lastPoint]);

	for(int i = 1; i <= 1000; i++){
		linkOfState[i] = 0;
		vc[i].clear();
		lastPoint = 0;
		dp[i] = 0;
		spendTime[i] = 0;
	}
}