#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> vc;
int N;

int main(){
	int num;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		if(vc.size() == 0){
			vc.push_back(num);
		}else if(vc.back() < num){
			vc.push_back(num);
		}else if(vc.back() >= num){
			int index = upper_bound(vc.begin(), vc.end(), num) - vc.begin();
			vc[index] = num;
		}
	}

	printf("%d", N - vc.size());
}