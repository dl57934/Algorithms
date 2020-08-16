#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> input();

int main(){
	vector<int> scale = input();
	int base = 1;
	for(auto sc : scale){
		if(base < sc){
			break;
		}else{
			base+=sc;
		}
	}

	printf("%d", base);
}


vector<int> input(){
	scanf("%d", &N);
	vector<int> scale(N, 0);

	for(int i = 0; i < N; i++)
		scanf("%d", &scale[i]);

	sort(scale.begin(), scale.end());

	return scale;
}