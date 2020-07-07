#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int > >result;
vector<int> friends[105];
int N, M;
int map[105][105];

void input();
void bfs(int start);
int main(){
	input();
	for(int i = 1; i <= N; i++)
		bfs(i);
	sort(result.begin(), result.end());

	printf("%d", result[0].second);
}

void input(){
	int f1, f2;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++){
		scanf("%d %d", &f1, &f2);
		friends[f1].push_back(f2);
		friends[f2].push_back(f1);
	}
}

void bfs(int start){
	queue <pair<int, int> > qu;
	int check[105] = {0, };
	int subResult = 0; 
	qu.push(make_pair(start, 0));
	check[start] = 1;
	while(!qu.empty()){
		pair<int, int> now = qu.front();
		int nowPoint = now.first;
		int distance = now.second;
		subResult+=distance;
		map[start][nowPoint] = distance;
		qu.pop();
		for(auto fi : friends[nowPoint]){
			if(check[fi] == 0){
				qu.push(make_pair(fi, distance+1));
				check[fi] = 1;
			}
		}
	}
	result.push_back(make_pair(subResult, start));
}