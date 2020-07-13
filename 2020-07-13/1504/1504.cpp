#include <cstdio>
#include <queue>
#include <vector>
#define point pair<int, int>
using namespace std;


vector <point> map[802];

int N, E, start, backPoint;
int vertex[802];
int INF = 98765432;
void init();
void input();
int dajickstra(int start, int backPoint);

int main(){
	input();
	int start1  = dajickstra(1, start);
	int start2 = dajickstra(1, backPoint);

	int mid1 = dajickstra(start, backPoint);
	int mid2 = dajickstra(backPoint, start);

	int end1 = dajickstra(backPoint, N);
	int end2 = dajickstra(start, N);

	if(start1 + end1+mid1 > start2 + end2 + mid2){
		if(start2 == INF || end2 == INF || mid2 == INF)
			printf("-1");
		else
			printf("%d", start2 + end2+mid2);
	}
	else{
		if(start1 == INF || end1 == INF|| mid1 == INF)
			printf("-1");
		else
			printf("%d", start1 + end1+mid1);
	}
}

void init(){
	for(int i = 1; i <= N; i++)
		vertex[i] = INF;
}

void input(){
	int a, b, c;
	scanf("%d %d", &N, &E);

	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(c, b));
		map[b].push_back(make_pair(c, a));
	}

	scanf("%d %d", &start, &backPoint);
}

int dajickstra(int start, int backPoint){
	init();
	int check[802]= {0, };
	vertex[start] = 0;
	priority_queue <point, vector<point>, greater<point> > pq;	
	pq.push(make_pair(0, start));
	while(!pq.empty()){
		point now = pq.top();
		int weight = now.first;
		int nowPoint = now.second;	
		check[nowPoint] = 1;
		pq.pop();
		for(auto next:map[nowPoint]){
			int nextWeight = next.first;
			int nextPoint = next.second;
			if(check[nextPoint] == 0){
				if(weight + nextWeight < vertex[nextPoint]){
					vertex[nextPoint] = weight + nextWeight;
					pq.push(make_pair(vertex[nextPoint], nextPoint));
				}
			}
		}
	}

	return vertex[backPoint];
}