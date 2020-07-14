#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define point pair<int, int>
using namespace std;

vector<point> vc[2002];
int destination[102];
int INF = 9876543;
int n, m, t, s, g, h;
void input();
int dajickstra(int start, int end);

int main(){
	int testCase;
	scanf("%d", &testCase);

	for(int cs = 0; cs < testCase; cs++){
		input();
		int start1 = dajickstra(s, g);
		int start2 = dajickstra(s, h);
		int start;
		if(start1 < start2)
			start = start1;
		else
			start = start2;
		int mid = dajickstra(g, h);
		sort(destination, destination+t);
		for(int dest = 0; dest < t; dest++){
			
			int end1 = dajickstra(h, destination[dest]);
			int end2 = dajickstra(g, destination[dest]);

			int subRoadDistance;
			int realResult = dajickstra(s, destination[dest]);
			if(end1 > end2){
				if(realResult == start + mid + end2)
					printf("%d ", destination[dest]);
			}else{
				if(realResult == start + mid + end1)
					printf("%d ", destination[dest]);
			}
			
		}


		for(int i = 1; i <= n; i++)
			vc[i].clear();
	}
}

void input(){
	int a, b, d;
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d", &s, &g, &h);

	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &d);
		vc[a].push_back(make_pair(d, b));
		vc[b].push_back(make_pair(d, a));
	}

	for(int i = 0; i < t; i++){
		scanf("%d", &destination[i]);
	}
}

int dajickstra(int start, int end){
	priority_queue <point, vector<point>, greater<point> > pq;
	int vertex[2002] = {0, };
	int check[2002] = {0, };
	for(int i = 1; i <= n; i++)
		vertex[i] = INF;
	vertex[start] = 0;
	pq.push(make_pair(0, start));

	while(!pq.empty()){
		point now = pq.top();
		int nowWeight = now.first;
		int nowPoint = now.second;
		pq.pop();
		if(check[nowPoint]) continue;
		check[nowPoint] = 1;
		for(auto next : vc[nowPoint]){
			int nextWeight = next.first;
			int nextPoint = next.second;
			if(nowWeight + nextWeight < vertex[nextPoint]){
				vertex[nextPoint] = nowWeight + nextWeight;
				pq.push(make_pair(vertex[nextPoint], nextPoint));
			}
		}
	}

	return vertex[end];
}