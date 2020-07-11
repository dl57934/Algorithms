#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vc;
int N;

void input();

int main(){	
	input();

	int target = 1;
	for(int i = 0; i < N; i++){
		if(target < vc[i]){
			break;
		}
		target += vc[i];
	}

	printf("%d", target);
}

void input(){
	int num;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		vc.push_back(num);
	}

	sort(vc.begin(), vc.end());
}