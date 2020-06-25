#include <cstdio>
#include <vector>

using namespace std;

vector <int> computers[102];
int check[102];

void input();
void dfs(int point);
int answer = 0;

int main(){
	input();
	printf("%d", answer-1);
}

void input(){
	int computer, set;
	int start, end;
	scanf("%d %d", &computer, &set);

	for(int i = 0; i < set; i++){
		scanf("%d %d", &start, &end);
		computers[start].push_back(end);
		computers[end].push_back(start);
	}

	dfs(1);
}

void dfs(int point){
	answer+=1;
	check[point] = 1;

	for(int nextPoint : computers[point]){
		if(check[nextPoint] == 0){
			dfs(nextPoint);
		}
	}
}