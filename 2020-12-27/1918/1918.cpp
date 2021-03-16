#include <cstdio>
#include <string>
#include <stack>
using namespace std;
char orderMath[105];
string order;
stack<char> st;

void solve();

int main(){
	scanf("%s", &orderMath);
	order = orderMath;
	solve();
}

void solve(){
	for(int i = 0; i < order.size(); i++){
		
		if(order[i] <= 'Z' && order[i] >= 'A'){
			printf("%c", order[i]);
		}else if(order[i] == ')'){
			while(st.top() != '('){						
				printf("%c", st.top());
				st.pop();					
			}
			if(st.top() == '(')
				st.pop();
		}else{
			
				if(order[i] == '-' || order[i] == '+'){
					while(!st.empty()){
						if(st.top() == '(')
							break;
						printf("%c", st.top());
						st.pop();
					}
				}else if(order[i] == '*' || order[i] == '/'){
					while(!st.empty()){
						if(st.top() =='(' || st.top() == '-' || st.top() == '+')
							break;
						printf("%c", st.top());
						st.pop();
					}
				}

			st.push(order[i]);
		}
	}

	while(!st.empty()){
		printf("%c", st.top());
		st.pop();
	}
}



