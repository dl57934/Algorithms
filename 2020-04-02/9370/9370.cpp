#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t;
int s, g, h;
int status = 0;
int visited[2002];
int vertex[2002];
int INF = 987654321;
int assumeDestination[2002];
vector <pair<int, int> > map[2002];
int path[2002];

void input();
void init();
void initPoint();
void getPath(int start);
int dajickstra(int start, int end);

int main(){
	int testCase;
	scanf("%d", &testCase);
	for(int i = 0; i < testCase; i++){
		input();
		sort(assumeDestination, assumeDestination+t);
		int first;
		int firstOne = dajickstra(s, g);
		int secondOne = dajickstra(s, h);

		if(firstOne > secondOne)
			first = secondOne;
		else
			first = firstOne;
		
		int mid = dajickstra(g, h);
		int last;
		for(int j = 0; j < t; j++){
			int lastOne = dajickstra(g, assumeDestination[j]);
			int lastSecond = dajickstra(h, assumeDestination[j]);
			if(lastOne > lastSecond){
				last = lastSecond;
				int distances = first + mid + last;
				if(distances == path[assumeDestination[j]])
					printf("%d ", assumeDestination[j]);
			}
			else{
				last = lastOne;
				int distances = first + mid + last;
				if(distances == path[assumeDestination[j]])
					printf("%d ", assumeDestination[j]);
			}
			printf("\n");
		}
		init();
	}

}

void init(){
	status = 0;
	for(int i = 1; i <= n; i++){
		map[i].clear();
	}
}

void initPoint(){
	for(int i = 1; i <= n; i++){
		visited[i] = 0;
		vertex[i] = INF;
	}
}

void input(){
	int start, end, weight;
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d", &s, &g, &h);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &start, &end, &weight);
		map[start].push_back(make_pair(weight, end));
		map[end].push_back(make_pair(weight, start));

	}

	for(int i = 0; i < t; i++){
		scanf("%d", &assumeDestination[i]);
	}
	
}

int dajickstra(int start, int end){
	initPoint();
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qu;
	qu.push(make_pair(0, start));
	vertex[start] = 0;
	while(!qu.empty()){
		pair<int, int> point = qu.top();
		int nowWeight = point.first;
		int nowPoint = point.second;
		qu.pop();
		for(int i = 0; i < map[nowPoint].size(); i++){
			pair<int, int> destination = map[nowPoint][i];
			int moveWeight = destination.first;
			int destinationPoint = destination.second;
			
				if(vertex[destinationPoint] > moveWeight + nowWeight){
					vertex[destinationPoint] = moveWeight + nowWeight;
					qu.push(make_pair(vertex[destinationPoint], destinationPoint));
					visited[destinationPoint] = 1;
				}
		}

	}


	if(status == 0){
		for(int j = 0; j < t; j++)
			path[assumeDestination[j]] = vertex[assumeDestination[j]];
		status =1;
	}
	return vertex[end];
}