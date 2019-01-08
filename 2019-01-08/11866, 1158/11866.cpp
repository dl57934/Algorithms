#include <cstdio>
#include <queue>

using namespace std;
queue <int> qu;

int main(){
	int N, M;
	int iteratorIdx = 1;
	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; i++)
		qu.push(i);

	printf("<");
	while(!qu.empty()){
		if(iteratorIdx == M){
			if(qu.size() == 1)
				printf("%d", qu.front());
			else 
				printf("%d, ", qu.front());
			iteratorIdx=0;
			qu.pop();
		}else{
			qu.push(qu.front());
			qu.pop();
		}
		iteratorIdx+=1;
	}


	printf(">");	
}