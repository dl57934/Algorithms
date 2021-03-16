#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > numBox;

bool comp(pair<int, int> a, pair<int, int> b);

int main(){
	int N, maxCount = 0;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		int firstNum, secondNum;
		scanf("%d %d", &firstNum, &secondNum);
		numBox.push_back(make_pair(firstNum, secondNum));
	}

	sort(numBox.begin(), numBox.end(), comp);

	int endTime = 0;

	for(auto num : numBox){
		if(num.first >= endTime){
			maxCount += 1;
			endTime = num.second;
		}
	}
	printf("%d", maxCount);
}

bool comp(pair<int, int> a, pair<int, int> b){
	if(a.second > b.second) return false;
	if(a.second < b.second) return true;
	return a.first < b.first;
}