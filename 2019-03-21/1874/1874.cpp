
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

stack<int> st;
string result;
int prevNum = 0;

int isPushPop(int number);
void push(int limit);
int pop(int findNum);
int isNo(string str);



int main(){
	int N, number;
	
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &number);
		if(isPushPop(number)){
			push(number);
			prevNum = number;
		}
		else
			if(pop(number) == 0){
				printf("NO");
				return 0;
			}
		
	}
	printf("%s", result.c_str());
}

int isPushPop(int number){
	if(prevNum < number)
		return 1;
	else
		return 0;
}

void push(int limit){
	for(int i = prevNum+1; i < limit; i++){
		st.push(i);
		result+="+\n";
	}
	result+="+\n";
	result+="-\n";
	
}

int pop(int findNum){
	if(st.top() != findNum)
		return 0;
	
	st.pop();
	result+="-\n";
	return 1;
}


