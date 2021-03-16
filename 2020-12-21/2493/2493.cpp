#include <cstdio>
#include <stack>

using namespace std;

int arr[500002];

int main(){
	int N, num;
	stack<pair<int, int> > st;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++){
		scanf("%d", &num);

		if(st.empty()){
			printf("0 ");
			st.push(make_pair(num, i));
		}else{
				while(!st.empty()){
					
					if(st.top().first >= num){

						break;
					}
					st.pop();
				}

				

				if(st.empty())
					printf("0 ");
				else
					printf("%d ", st.top().second);
				st.push(make_pair(num, i));
		}
	}
}