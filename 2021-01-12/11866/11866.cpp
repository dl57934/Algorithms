#include <cstdio>
#include <queue>

using namespace std;

queue <int> qu;

int main(){
	int N, K;
	scanf("%d %d", &N, &K);

	for(int i = 1; i <= N; i++)
		qu.push(i);
	
	int index = 0;
	printf("<");
	while(!qu.empty()){
		if(qu.size() == 1){
			printf("%d", qu.front());
			qu.pop();
		}
		else if(index == K-1){
			printf("%d, ", qu.front());
			qu.pop();
			index = 0;
		}else{
			qu.push(qu.front());
			qu.pop();
			index++;
		}
		
	}

	printf(">");
}