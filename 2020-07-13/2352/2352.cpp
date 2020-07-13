#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> systems;
int N;
void input();

int main(){
	input();
}

void input(){
	int num;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		if(systems.size() == 0){
			systems.push_back(num);
		}else if(systems.back() < num){
			systems.push_back(num);
		}else{
			int index = lower_bound(systems.begin(), systems.end(), num)-systems.begin();
			systems[index] = num;
		}
	}

	printf("%d", systems.size());
}