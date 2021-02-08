#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > dp(103);
vector<pair<int, pair<int, int> > > sub;
vector<pair<int, pair<int, int> > > order;
vector<int> result;

void solve();
bool isCorrectBox(int prev, int now);

int N;
int main(){	
	int area, height, weight;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d %d", &area, &height, &weight);
		sub.push_back(make_pair(area, make_pair(height, weight)));
		order.push_back(make_pair(area, make_pair(height, i)));
	}

	sort(sub.begin(), sub.end(), greater<pair<int, pair<int, int> > >());
	sort(order.begin(), order.end(), greater<pair<int, pair<int, int> > >());
	solve();
}

void solve(){
	dp[0].first = sub[0].second.first;
	dp[0].second = 0;


	for(int now = 1; now < N; now++){
		dp[now].first = sub[now].second.first;
		for(int prev = 0; prev < now; prev++){
			if(isCorrectBox(prev, now)){
				if(dp[now].first < dp[prev].first + sub[now].second.first){
					dp[now].first = dp[prev].first + sub[now].second.first;
					dp[now].second = prev;
				}
			}
		}
	}

	// dp 코드

	int maxValue = 0, maxIndex;

	for(int i = 0; i < N; i++){
		if(maxValue < dp[i].first){
			maxValue = dp[i].first;
			maxIndex = i;
		}
	}

	int compareNum = 0;

	while(maxValue !=  compareNum){
		result.push_back(order[maxIndex].second.second);
		compareNum +=order[maxIndex].second.first;
		maxIndex = dp[maxIndex].second;
	}

	printf("%d\n", result.size());

	for(auto rank : result){
		printf("%d\n", rank+1);
	}
}


bool isCorrectBox(int prev, int now){
	if(sub[now].first < sub[prev].first && sub[now].second.second < sub[prev].second.second)
		return true;
	return false;
}