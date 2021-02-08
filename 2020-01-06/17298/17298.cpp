#include <cstdio>
#include <stack>

using namespace std;

int N;
int arr[1000002];
stack<pair<int, int> > st;

int main(){
	int num;
	scanf("%d", &N);
	arr[N-1] = -1;
	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		if(i == 0 || st.size() == 0){
			st.push(make_pair(num, 0));
		}else if(st.top().first >= num){
			st.push(make_pair(num, i));
		}else if(st.top().first < num){
			while(!st.empty()){
				pair<int, int> prev = st.top();
				if(prev.first >= num){
					break;
				}
				arr[prev.second] = num;
				st.pop();
			}
			st.push(make_pair(num, i));
		}
	}

	for(int i = 0; i < N; i++){
		if(arr[i] == 0)
			printf("-1 ");
		else
			printf("%d ", arr[i]);
	}
}