#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, order, start, findNum;
vector<int> family[102];
int check[102];
queue <pair<int, int> > qu;

void input();
int bfs();

int main(){
	input();
	if(bfs())
		return 0;
	printf("-1");
}

int bfs(){
	while(!qu.empty()){
		pair<int, int> now = qu.front();
		qu.pop();
		check[now.first] = 1;
		if(now.first == findNum){
			printf("%d", now.second);
			return 1;
		}

		for(auto son : family[now.first]){
			if(!check[son]){
				qu.push(make_pair(son, now.second+1));
			}
		}
	}
	return 0;
}

void input(){
	scanf("%d%d%d", &N, &start, &findNum);
	scanf("%d", &order);
	int person1, person2;
	for(int i = 0; i < order; i++){
		scanf("%d %d", &person1, &person2);
		family[person1].push_back(person2);
		family[person2].push_back(person1);
	}
	qu.push(make_pair(start, 0));
}

