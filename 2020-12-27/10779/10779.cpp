#include <cstdio>
#include <stack>
#include <string>
using namespace std;

stack<char> st;
int sum = 0;
char inputBracket[100002];
string input;
void solve();

int main(){
	scanf("%s", &inputBracket);
	input = inputBracket;
	solve();
	printf("%d", sum);
}

void solve(){
	int beam = 0;
	for(int i = 0; i < input.size(); i++){
		if(st.empty() || input[i] == '('){	
			if(input[i + 1] == ')'){
				sum+=st.size();
				i+=1;
			}else{
				st.push(input[i]);
			}
		}else if(input[i] == ')'){
			st.pop();
			sum+=1;
		}
	}
}	