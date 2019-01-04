#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

stack <char> ps;


void push(char inputPs[]);
int checkYesOrNo();
void stackInit();

int main(){
	int T;
	char inputPs[52];
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%s", &inputPs);
		push(inputPs);
		if(checkYesOrNo())
			printf("YES\n");
		else
			printf("NO\n");
		stackInit();
	}
}	

void stackInit(){
	while(!ps.empty())
		ps.pop();
}

void push(char inputPs[]){
	int length = strlen(inputPs);
	for(int i = 0; i < length; i++)
		ps.push(inputPs[i]);
}


int checkYesOrNo(){
	char receivePs[52];
	int id = 0;
	while(!ps.empty()){
		if(ps.top() == '('){
			if(id-1 <0)
				return 0;
			else if(receivePs[id-1] == ')'){
				receivePs[--id] = '\0';
				ps.pop();
			}
			else
				return 0;
			
		}else{
			receivePs[id] = ps.top();
			id++;
			ps.pop();
		}
	}

	int length = strlen(receivePs);
	if(length > 0)
		return 0;
	return 1;
}