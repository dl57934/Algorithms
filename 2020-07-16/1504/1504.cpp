#include <cstdio>
#include <queue>
#include <vector>
#define point pair<int, int>
using namespace std;

int INF = 98765432;
int N, E;
int midPoint1, midPoint2;
vector<point> vc[802];

void input();
int dajickStra(int start, int destination);

int main(){
	input();
	int start1 = dajickStra(1, midPoint1);
	int start2 = dajickStra(1, midPoint2);
	int mid = dajickStra(midPoint1, midPoint2);
	int end1 = dajickStra(midPoint2, N);
	int end2 = dajickStra(midPoint1, N);

	long long result1 = start1 + mid + end1;
	long long result2 = start2 + mid + end2;

	if(result1 >= INF && result2 >= INF){
		printf("-1");
		return 0;
	}else if(result1 > result2){
		printf("%lld", result2);
		return 0;
	}else{
		printf("%lld", result1);
		return 0;
	}
}

 void input(){
 	scanf("%d %d", &N, &E);
 	int start, destination, cost;
 	for(int edge = 0; edge < E; edge++){
 		scanf("%d %d %d", &start, &destination, &cost);
 		vc[start].push_back(make_pair(cost, destination));
 		vc[destination].push_back(make_pair(cost, start));
 	}	

 	scanf("%d %d", &midPoint1, &midPoint2);
 }

 int dajickStra(int start, int destination){
 	int check[802] = {0, };
 	int vertex[802] = {0, };

 	for(int i = 1; i <= N; i++)
 		vertex[i] = INF;
 	vertex[start] = 0;
 	priority_queue <point, vector<point>, greater<point> > pq;
 	pq.push(make_pair(0, start));

 	while(!pq.empty()){
 		point now = pq.top();
 		int cost = now.first;
 		int nowPoint = now.second;
 		pq.pop();
 		if(check[nowPoint])
 			continue;
 		check[nowPoint] = 1;

 		for(auto next : vc[nowPoint]){
 			int nextCost = next.first;
 			int nextPoint = next.second;
 			if(vertex[nextPoint] > nextCost + cost){
 				vertex[nextPoint] = nextCost + cost;
 				pq.push(make_pair(vertex[nextPoint], nextPoint));
 			}
 		}
 	}

 	return vertex[destination];
 }