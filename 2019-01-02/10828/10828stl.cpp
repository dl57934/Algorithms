#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

#define PUSH "push"
#define POP "pop"
#define SIZE "size"
#define EMPTY "empty"
#define TOP "top"

stack <int> st;

void printResult(int n);

int main(){
	char method[10];
	int input;
	int N;

	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%s", method);
		if(!strcmp(method, PUSH)){
			scanf("%d", &input);
			st.push(input);
		}
		else if(!strcmp(method, POP)){
			if(st.empty())
				printResult(-1);
			else{
				printResult(st.top());
				st.pop();
			}
		}
		else if(!strcmp(method, SIZE))
			printResult(st.size());
		
		else if(!strcmp(method, EMPTY)){
			if(st.empty())
				printResult(1);
			else
				printResult(0);
		}
		
		else if(!strcmp(method, TOP)){
			if(st.empty())
				printResult(-1);
			else 
				printResult(st.top());
		}
	}
	return 0;
}

void printResult(int n){
	printf("%d\n", n);
}