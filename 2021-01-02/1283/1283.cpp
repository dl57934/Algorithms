#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define element pair<int, int>

priority_queue <element, vector<element>, greater<element> > pq;
vector<pair<int, int> > vc[5002];
int allDistance[5002];
int weight[5002];
int N, M, X;

void init(int start);
void solve();
void dajickstra(int start);


int main(){
	int start, end, cost;
	scanf("%d %d %d", &N, &M, &X);

	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &start, &end, &cost);
		vc[start].push_back(make_pair(end, cost));
	}


	for(int i = 1; i <= N; i++){
		init(i);
		dajickstra(i);
	}

	printf("%d", *max_element(allDistance, allDistance + N+1));

}

void init(int start){
	for(int i = 1; i <= N; i++)
		weight[i] = 987654321;
	weight[start] = 0;
}

void dajickstra(int start){
	int visted[5002] = {0, };
	pq.push(make_pair(0, start));

	while(!pq.empty()){
		int cost = pq.top().first;
		int now = pq.top().second;
		visted[now] = 1;
		pq.pop();
		for(auto nextInfo : vc[now]){
			int nextPoint = nextInfo.first;
			int nextCost = nextInfo.second;
			if(!visted[nextPoint] && weight[nextPoint] > cost + nextCost){
				weight[nextPoint] = cost + nextCost;
				pq.push(make_pair(weight[nextPoint], nextPoint));
			}
		}
	}

	if(start == X){
		for(int i = 1; i <= N; i++){
			allDistance[i]+=weight[i];
		}
	}else{
		allDistance[start]+=weight[X];
	}
}