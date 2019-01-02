#include <cstdio>
#include <stack>
#include <string>

using namespace std;

stack <int> st;
string result;
void push(int num);
int canPop(int num);

int main(){
	int N;
	scanf("%d", &N);
	int max = 1;
	int inputNum;
	
	push(0);

	for(int i = 1; i <= N; i++){
		scanf("%d", &inputNum);
		if(max <= inputNum ){
			for(int i = max; i<=inputNum; i++){
				push(i);
				result.append("+\n");
			}
			max = inputNum+1;
			st.pop();
			result.append("-\n");
		}else {
			if(!canPop(inputNum))
				return 0;
		}		
	}

	printf("%s", result.c_str());
}

int canPop(int num){
	while(!st.empty()){
		if(st.top() == num){
			st.pop();
			result.append("-\n");
			return 1;
		}else{
			st.pop();
		}
	}
	printf("NO");
	return 0;
}

void push(int num){
	st.push(num);
}