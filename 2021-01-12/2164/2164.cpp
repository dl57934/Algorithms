#include <queue>
#include <cstdio>

using namespace std;

int N;
queue<int> qu;
int main(){
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
		qu.push(i);

	while(!qu.empty()){
		
		if(qu.size() == 1){
			printf("%d", qu.front());
			break;
		}
		qu.pop();

		if(qu.size() == 1){
			printf("%d", qu.front());
			break;
		}

		qu.push(qu.front());
		qu.pop();

		
	}
}