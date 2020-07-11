#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> lis;

void input();

int main(){
	input();
	printf("%d", lis.size());
}

void input(){
	int compareNum;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &compareNum);
		if(lis.size() == 0){
			lis.push_back(compareNum);
		}else if(lis.back() < compareNum){
			lis.push_back(compareNum);
		}
		else{
			int index = lower_bound(lis.begin(), lis.end(), compareNum)-lis.begin();
			lis[index] = compareNum;
		}
	}
}