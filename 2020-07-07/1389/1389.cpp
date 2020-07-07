#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> friendship[103];
vector<pair<int, int> > result;
int N, M;
void input();
void bfs(int start);

int main(){
	input();
	for(int startFriend = 1; startFriend <= N; startFriend++){
		bfs(startFriend);
	}
	sort(result.begin(), result.end());
	printf("%d", result[0].second);

}

void input(){
	scanf("%d %d", &N, &M);
	int friend1, friend2;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &friend1, &friend2);
		friendship[friend1].push_back(friend2);
		friendship[friend2].push_back(friend1);
	}
}

void bfs(int start){
	int check[1005] = {0, };
	queue <pair<int, int> > qu;
	qu.push(make_pair(start, 0));
	int subDistance=0;
	check[start] = 1;
	while(!qu.empty()){
		pair<int, int> now = qu.front();
		int nowIndex = now.first;
		int distance = now.second;
		subDistance+=distance;
		qu.pop();
		for(auto nextFriend:friendship[nowIndex]){
			if(check[nextFriend] == 0){
				check[nextFriend] = 1;
				qu.push(make_pair(nextFriend, distance+1));
			}
		}
	}
	result.push_back(make_pair(subDistance, start));
}