#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

char inputMessage[500052];
string input, result;
stack<int> st;
int main(){
	int N, K, remove = 0;
	scanf("%d %d", &N, &K);
	int wantSize  = N - K;

	scanf("%s", &inputMessage);
	input = inputMessage;

	for(int i = 0; i < N; i++){
		int nowNumber = input[i] -'0';
		if(st.empty()){
			st.push(nowNumber);
		}
		else{
			if(st.top() < nowNumber && K > remove){
				while(!st.empty() && K > remove){
					if(st.top() >= nowNumber)
						break;
					st.pop();
					remove+=1;	
				}
				st.push(nowNumber);
			}else{
				st.push(nowNumber);
			}
		}
	}

	while(!st.empty()){
		result.push_back(st.top()+'0');
		st.pop();
	}

	reverse(result.begin(), result.end());

	for(int i = 0; i < wantSize; i++)
	printf("%c", result[i]);
}