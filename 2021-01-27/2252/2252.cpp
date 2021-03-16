#include <cstdio>
#include <vector>
#include <stack>

using namespace std;
stack<int> st;
vector<int> vc[32001];
int visit[32003], isFinish[32003];

void topologySort(int num);


int main(){
	int N, M;
	int start, end;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++){
		scanf("%d %d", &start, &end);
		vc[start].push_back(end);
	}

	for(int i = 1; i <= N; i++){
		if(visit[i] == 0){
			topologySort(i);
		}
	}

	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
}

void topologySort(int num){
	visit[num] = 1;
	for(auto next : vc[num]){
		if(visit[next] == 0){
			topologySort(next);
		}else if(isFinish[num] == 0){
			
		}
	}

	isFinish[num] = 1;

	st.push(num);
}