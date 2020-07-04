#include <cstdio>
#include <queue>

using namespace std;

int N, M;
vector<int> map[1002];
queue<int> qu;

void input();
void init();
void bfs(int start);

int main(){
	input();
}

void init(){
	for(int i = 1; i <= 1000; i++)
		map[i].clear();

}

void input(){
	int T; 
	int start, end;
	scanf("%d", &T);

	for(int cs = 0; cs < T; cs++){
		scanf("%d %d", &N, &M);

		for(int domestic = 0; domestic < M; domestic++){
			scanf("%d %d", &start, &end);
			map[start].push_back(end);
			map[end].push_back(start);
		}
		
		bfs(1);
		init();
	}


}

void bfs(int start){
	vector<int> check(1003);
	check[start] = 1;
	int result = 0;
	qu.push(start);
	while(!qu.empty()){
		int now = qu.front();
		
		qu.pop();
		for(auto next : map[now]){
			if(check[next] == 0){
				check[next] = 1;
				result += 1;
				qu.push(next);
			}
		}
	}

	printf("%d\n", result);
}


