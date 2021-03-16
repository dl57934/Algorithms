#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> location, diff;
long long save;
int N, K, arr[10002];

pair<int, int> setDiff(int startIndex);

int main(){
	int num;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		location.push_back(num);
	}

	sort(location.begin(), location.end());

	for(int i = 1 ; i < location.size(); i++)
		diff.push_back(location[i] - location[i-1]);
	
	sort(diff.begin(), diff.end());

	for(int i = 0; i < N - K; i++)
		save += diff[i];

	printf("%lld", save);
}
