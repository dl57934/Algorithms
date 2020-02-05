#include <cstdio>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

stack <char> wareHouse;

void calculator(string order);
void emptyStack();

int main(){
	string order;
	for(;;){
		getline(cin, order);
		if(order == ".")
			break;
		calculator(order);
	}
}


void calculator(string order){
	for(int i = 0; i < order.size(); i++){
		if(order[i] == '[' || order[i] == '(')
			wareHouse.push(order[i]);
		else if(order[i] == ']' || order[i] == ')'){
			if(wareHouse.size() == 0){
				printf("no\n");
				return;
			}
			if(order[i] == ']'){
				if(wareHouse.top() == '[')
					wareHouse.pop();
				else if(wareHouse.top() == '(' || wareHouse.top() == ']' || wareHouse.top() == ')' || wareHouse.size() == 0){
					printf("no\n");
					emptyStack();
					return ;
				}
			}
			else if(order[i] == ')'){
				if(wareHouse.top() == '(')
					wareHouse.pop();
				else if(wareHouse.top() == '[' || wareHouse.top() == ']' || wareHouse.top() == ')' || wareHouse.size() == 0){
					printf("no\n");
					emptyStack();
					return ;
				}
			}	
		}
	}

	if(wareHouse.size() == 0)
		printf("yes\n");
	else
		printf("no\n");
	emptyStack();
}


void emptyStack(){
	while(!wareHouse.empty())
		wareHouse.pop();
}