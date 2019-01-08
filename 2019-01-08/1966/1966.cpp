#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

priority_queue <int> pq;
queue <pair<int, int> > qu;

void init();
int calculate(int M);

int main(){
	int T;
	int M, N;
	int importantDoc;
	scanf("%d", &T);
	for(int i =0; i < T; i++){
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; i++){
			scanf("%d", &importantDoc);
			pq.push(importantDoc);
			qu.push(make_pair(i, importantDoc));
		}
		printf("%d\n", calculate(M));
		init();
	}
}

int calculate(int M){
	int i = 1;
	while(!pq.empty()){
		if(pq.top() != qu.front().second){
			qu.push(qu.front());
			qu.pop();
		}else if(pq.top() == qu.front().second){
			if(M == qu.front().first){
				return i;
			}else{
				qu.pop();
				pq.pop();
				i+=1;
			}
		}
	}
}


void init(){	
	while(!pq.empty())
		pq.pop();
	while(!qu.empty())
		qu.pop();
}