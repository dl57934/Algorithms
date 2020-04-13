#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector <int> map[100002];
queue <int> qu;
int result[100002];

void bfs();

int main(){
	int N; 
	int parent, child;
	int tree[100002];
	scanf("%d", &N);

	for(int i = 1; i < N; i++){
		scanf("%d %d", &parent, &child);
		map[parent].push_back(child);
		map[child].push_back(parent) ;			
	}

	bfs();

	for(int i = 2; i <= N; i++)
		printf("%d\n", result[i]);

}

void bfs(){
	qu.push(1);
		
	while(!qu.empty()){
		int startPoint = qu.front();	
		qu.pop();
		for(int i = 0; i < map[startPoint].size(); i++){
			if(result[map[startPoint][i]] == 0){
				result[map[startPoint][i]] = startPoint;
				qu.push(map[startPoint][i]);
			}
		}
	}
}