#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int N, K;
queue <pair<int, int> > qu;
stack <int> st;
int distances[100002];
vector <int> history[100002];

void getTime();

int main(){
	scanf("%d %d", &N, &K);
	getTime();
	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
}


void getTime(){
	qu.push(make_pair(N, 0));
	while(!qu.empty()){
		pair<int, int> point = qu.front();
		int nowPoint = point.first;
		int nowTime = point.second;
		qu.pop();

		if(nowPoint == K){
			int index = nowPoint;
			st.push(K);
			for(int i = 0; i < nowTime; i++){
				st.push(history[index].front());	
				index = history[index].front();
			}
			printf("%d\n", nowTime);
			break;
		}

		distances[nowPoint] = 1;
		
		if(nowPoint * 2 <= 100000 && !distances[nowPoint*2] ){
			history[nowPoint*2].push_back(nowPoint);
			qu.push(make_pair(nowPoint * 2, nowTime+1));
		}
		if( nowPoint +1 <= 100000 && !distances[nowPoint+1]){
			history[nowPoint+1].push_back(nowPoint);
			qu.push(make_pair(nowPoint+1, nowTime+1));
		}
		if(nowPoint -1 >= 0 && nowPoint -1 <= 100000 && !distances[nowPoint-1]){
			history[nowPoint-1].push_back(nowPoint);
			qu.push(make_pair(nowPoint-1, nowTime+1));		
		}
	}
}