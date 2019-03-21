#include <queue>
#include <utility>
#include <cstdio>
#include <vector>

using namespace std;

queue <pair<int, int> > document; //first 중요도 second 문서 위치
priority_queue <int> pq;

void calculate(int documentSize, int nthPrint);
void init();

int main(){
	int N;
	int important;
	int documentSize = 0, nthPrint=0;
	scanf("%d", &N);


	for(int i = 0; i < N; i++){
		scanf("%d %d", &documentSize, &nthPrint);

		for(int j = 0; j < documentSize; j++){
			scanf("%d", &important);
			document.push(make_pair(important ,j));
			pq.push(important);
		}
		calculate(documentSize, nthPrint);
		init();
	}


}

void init(){
	while(!pq.empty())
		pq.pop();
	while(!document.empty())
		document.pop();
}

void calculate(int documentSize, int nthPrint){
	int count = 1;
	while(!document.empty()){
		if(pq.top() == document.front().first){
			if(nthPrint == document.front().second){
				printf("%d\n",count);
				return ;
			}
			count+=1;
			pq.pop();
			document.pop();
		}else {
			pair <int, int> oneDocument = document.front();
			document.push(oneDocument);
			document.pop();
		}
	}
}