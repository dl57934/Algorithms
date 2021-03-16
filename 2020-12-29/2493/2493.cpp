#include <cstdio>
#include <stack>

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	int num;
	stack<pair<int, int> > st;
	for(int i = 1; i <= N; i++){
		scanf("%d", &num);

		if(st.empty()){
			st.push(make_pair(num, i));
			printf("0 ");
		}else{
			while(!st.empty()){
				if(st.top().first>= num)
					break;
				st.pop();
			}

			if(st.empty()){
				st.push(make_pair(num, i));
				printf("0 ");
			}
			else{
				printf("%d ", st.top().second);
				st.push(make_pair(num, i));				
			}
		}

	}
}