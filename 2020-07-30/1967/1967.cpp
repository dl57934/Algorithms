#include <cstdio>
#include <vector>
#include <queue>
#define point pair<int, int>
using namespace std;

int N, longestLength;
vector<point> line[10002];
int findLongestNode(int start);
void input();

int main(){
	scanf("%d", &N);
	input();
	int anotherPoint = findLongestNode(1);
	findLongestNode(anotherPoint);

	printf("%d", longestLength);
}

void input(){
	int parent, child, cost;
	for(int i = 0; i < N-1; i++){
		scanf("%d %d %d", &parent, &child, &cost);
		line[parent].push_back(make_pair(child, cost));
		line[child].push_back(make_pair(parent, cost));
	}
}

int findLongestNode(int start){
	queue<point> qu;
	qu.push(make_pair(start, 0));
	int vertex[10002] = { 0, };
	int check[10002] = { 0, };

	while(!qu.empty()){
		point base = qu.front();
		qu.pop();
		check[base.first] = 1;
		for(auto next : line[base.first]){
			if(check[next.first] == 0){
				vertex[next.first] = next.second + base.second;
				qu.push(make_pair(next.first,vertex[next.first]));
			}
		}
	}

	int checkMaxNum = 0;
	int selectPoint; 
	for(int i = 1; i <= N; i++){
		if(vertex[i] > checkMaxNum){
			checkMaxNum = vertex[i];
			selectPoint = i;
		}
	}	
	longestLength = checkMaxNum;

	return selectPoint;
}