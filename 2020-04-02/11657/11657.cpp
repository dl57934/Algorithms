#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;
int vertex[502];
vector <pair<pair<int ,int>, int> > path;
int INF = 987654321;

void init();
void input();
void ford();


int main(){
	input();
	init();
	ford();

	for(int line = 0; line < path.size(); line++){
			pair<int, int> point = path[line].first;
			int start = point.first;
			int end = point.second;
			int weight = path[line].second;
			if(vertex[start] == INF)
				continue;
			if( vertex[end] > weight + vertex[start]){
				printf("-1\n");
				return 0;
			}
	}


	for(int i = 2; i <= N; i++){
		if(vertex[i] == INF)
			printf("-1\n");
		else
			printf("%d\n", vertex[i]);
	}
}

void init(){
	for(int i = 1; i <= N; i++)
		vertex[i] = INF;
	vertex[1] = 0;
}

void input(){
	int start, destination, weight;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= M; i++){
		scanf("%d %d %d", &start, &destination, &weight);
		path.push_back(make_pair(make_pair(start, destination), weight));
	}
}

void ford(){
	for(int ver = 1; ver <= N; ver++){
		for(int line = 0; line < path.size(); line++){
			pair<int, int> point = path[line].first;
			int start = point.first;
			int end = point.second;
			int weight = path[line].second;
			if(vertex[start] == INF)
				continue;
			if( vertex[end] > weight + vertex[start])
				vertex[end] = weight + vertex[start];
		}
	}
}