#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int arr[100002], visited[100002], check[100002];
void solve();
int start;
vector<int> point;
int N, operationN;
int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
		solve();
}

void dfs(int x);

void solve(){
	
	scanf("%d", &N);
	operationN = N;
	for(int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
		if(i == arr[i]){
			visited[i] = 1;
		}
	}

	for(int i = 1; i <= N; i++){
		if(visited[i] == 0){
			start = i;
			dfs(i);
			point.clear();
		}else if(i == arr[i] && visited[i] == 1){
			operationN-=1;
		}
	}
	
	for(int i = 1; i <= N; i++){
		arr[i] = 0;
		visited[i] = 0;
		check[i] = 0;
	}

	printf("%d\n", operationN);
}

void dfs(int x){
	visited[x] = 1;
	check[x] = 1;
	point.push_back(x);
	

	if(visited[arr[x]] == 0){
		dfs(arr[x]);
	}else if(check[arr[x]] == 1){
		auto missing = find(point.begin(), point.end(), arr[x]);
		auto index_missing = distance(point.begin(), missing);
		operationN-= point.size() - index_missing;
	}
}