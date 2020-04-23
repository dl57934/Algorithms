#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pi;
stack <int> st;
priority_queue <pi, vector<pi>, greater<pi> > pq;
int startPoint, endPoint;
int n, m;
int checked[1002];
int vertex[1002];
int pointDistance[1002];
vector <pair<int, int> > vc[1002];

void input();
void dajickstra();

int main(){
	input();
	dajickstra();

	int index = endPoint;
	st.push(endPoint);
	while(index != startPoint){
		st.push(vertex[index]);
		index = vertex[index];
	}

	printf("%d\n%d\n", pointDistance[endPoint], st.size());

	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}

}

void input(){
	scanf("%d %d", &n, &m);
	int start, end, weight;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &start, &end, &weight);
		vc[start].push_back(make_pair(weight, end));
	}
	scanf("%d %d", &startPoint, &endPoint);
	pq.push(make_pair(0, startPoint));
	for(int i = 1; i <= n; i++)
		pointDistance[i] = 987654321;
}

void dajickstra(){

	while(!pq.empty()){
		pi now = pq.top();
		int nowWeight = now.first;
		int nowPoint = now.second;
		pq.pop();
		checked[nowPoint] = 1;
		for(int i = 0; i < vc[nowPoint].size(); i++){
			pi next = vc[nowPoint][i];
			int nextWeight = next.first;
			int nextPoint = next.second;
			if(!checked[nextPoint] && nowWeight + nextWeight < pointDistance[nextPoint]){
				pointDistance[nextPoint] = nowWeight + nextWeight;
				pq.push(make_pair(pointDistance[nextPoint], nextPoint));
				vertex[nextPoint] = nowPoint;
			}
		}
	}
}