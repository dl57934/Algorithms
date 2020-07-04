#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue <pair<int, int> > qu;
vector<int> arr[103];
vector<int> check(103);
int map[103][103];
vector<pair<int,int> > result;
int N, M;
void init();
void input();
void findFriend();
void bfs(int x);

int main(){
	input();
	findFriend();
}

void init(){
	for(int i = 1; i <= 100; i++)
		check[i] = 0;
}

void input(){
	int friend1, friend2;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++){
		scanf("%d %d", &friend1, &friend2);
		arr[friend1].push_back(friend2);
		arr[friend2].push_back(friend1);
	}
}

void findFriend(){
	for(int i = 1; i <= N; i++){
		qu.push(make_pair(0, i));
		bfs(i);
		init();
	}


	sort(result.begin(), result.end());
	printf("%d", result[0].second);
}

void bfs(int x){
	int subResult = 0;
	check[x] = 1;
	while(!qu.empty()){
		int now = qu.front().second;
		int distances = qu.front().first;
		map[x][now] = distances;
		subResult+=distances;
		
		qu.pop();
		for(auto mid : arr[now]){
			if(check[mid] ==0){
				qu.push(make_pair(distances+1, mid));
				check[mid] = 1;
			}
		}
	}

	result.push_back(make_pair(subResult, x));
}