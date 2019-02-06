#include <cstdio>
#include <queue>

using namespace std;

queue <int> qu;


int main(){
	int N;
	int i = 1;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		qu.push(i);

	while(!qu.empty()){
			printf("%d ", qu.front());
			qu.pop();
			qu.push(qu.front());
			qu.pop();
	}
}