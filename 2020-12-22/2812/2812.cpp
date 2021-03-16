#include <cstdio>
#include <stack>

using namespace std;

int main(){
	int N, K, num, size;
	stack<int> st;

	scanf("%d %d", &N, &K);

	size = N-K;

	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		if(st.empty()){
			st.push(num);
		}
	}

	for(int i = 0; i < K; i++){
		printf("%d", st.top());
		st.pop();
	}
}