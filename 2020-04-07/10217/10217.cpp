#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int vertex[102][10002];
int INF = 987654321;

int minValue;


vector <pair<pair<int, int>, int> > vc[102];



int T;
int N, M, K;

void input();
void dajickstra();

int main(){
	input();
}

void input(){
	scanf("%d", &T);
	int u, v, c, d;
	for(int testCase = 0; testCase < T; testCase++){
		minValue = INF;
		for(int i = 1; i <= N; i++)
			vc[i].clear();

		scanf("%d %d %d", &N, &M, &K);
		for(int i = 0; i < K; i++){
			scanf("%d %d %d %d", &u, &v, &c, &d);
			vc[u].push_back(make_pair(make_pair(v, c), d));
		}

		for(int i = 2; i <= N; i++){
			for(int money = 1; money <= M; money++){
				vertex[i][money] = INF;
			}
		}
		
		dajickstra();
		for(int i = 1; i <= M; i++){
			if(vertex[N][i] < minValue)
			minValue = vertex[N][i];
		}
		if(minValue==INF)
			printf("Poor KCM\n");
		else
		printf("%d\n", minValue);
		
	}
}

void dajickstra(){
	priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >,greater<pair<pair<int, int>, int> > > qu;	
	qu.push(make_pair(make_pair(0, 1), 0)); // weight, point

	while(!qu.empty()){
		pair<int, int> previous = qu.top().first;
		int previousWeight = previous.first;
		int previousPoint = previous.second;
		int previousCost = qu.top().second;
		qu.pop();
		for(int i = 0; i < vc[previousPoint].size(); i++){
			pair<int, int> next = vc[previousPoint][i].first;
			int nextWeight = vc[previousPoint][i].second;
			int nextPoint = next.first;
			int cost = next.second;
			// printf("before If %d %d %d %d\n", previousPoint, nextPoint, previousWeight + nextWeight, pay[previousPoint] + cost);
			// printf("compare If %d %d %d %d\n", previousPoint, nextPoint, vertex[nextPoint], M);
				if(nextPoint != N && previousCost + cost == M)
						continue;
				if(previousWeight + nextWeight < vertex[nextPoint][previousCost + cost] && previousCost + cost <= M){
					vertex[nextPoint][previousCost + cost] = previousWeight + nextWeight;
					qu.push(make_pair(make_pair(previousWeight + nextWeight, nextPoint), cost+previousCost));
					// printf("after If %d %d %d %d\n", previousPoint, nextPoint, vertex[nextPoint], pay[nextPoint]);
			}
		}
	}
}