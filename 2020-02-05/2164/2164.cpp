#include <cstdio>
#include <deque>
using namespace std;

deque <int> dequ;

int N;

int main(){
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
		dequ.push_back(i);

	while(!dequ.empty()){
		if(dequ.size() == 1){
			printf("%d", dequ.front());
			break;
		}
		dequ.pop_front();
		if(dequ.size() == 1){
			printf("%d", dequ.front());
			break;
		}
		
		int n = dequ.front();
		dequ.push_back(n);
		dequ.pop_front();
	}
}