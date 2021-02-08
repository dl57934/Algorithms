#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> friendShip[52], member;
vector<pair<int, int> > result;
int N, friend1, friend2;
void bfs();

int main(){
	scanf("%d", &N);

	while(1){
		scanf("%d %d", &friend1, &friend2);
		if(friend1 == -1 && friend2 == -1)
			break;
		friendShip[friend1].push_back(friend2);
		friendShip[friend2].push_back(friend1);
	}
	bfs();
	sort(result.begin(), result.end());

	for(int i = 0; i < result.size(); i++){
		if(result[i].first == result[0].first){
			member.push_back(result[i].second);
		}
	}

	sort(member.begin(), member.end());

	printf("%d %d\n",result[0].first, member.size());

	for(int i = 0; i < member.size()-1; i++){
		printf("%d ", member[i]);
	}	
	printf("%d", member[member.size()-1]);
}

void bfs(){
	for(int i = 1; i <= N; i++){
		queue<pair<int, int > > qu;
		int visited[52] = {0, };
		qu.push(make_pair(i, 0));
		int score = 0;
		visited[i] = 1;
		while(!qu.empty()){
			pair<int, int> top = qu.front();
			qu.pop();
			if(score < top.second)
				score = top.second;
			for(auto next : friendShip[top.first]){
				if(!visited[next]){
					qu.push(make_pair(next, top.second+1));
					visited[next] = 1;
				}
			}
		}
		result.push_back(make_pair(score, i));
	}
}