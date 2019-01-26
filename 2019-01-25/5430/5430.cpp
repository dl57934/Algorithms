#include <cstdio>
#include <string>
#include <deque>
#include <iostream>

using namespace std;

void input();
void init(int *digit, int *value, int *numCount);
void inputDeque(int numCount, int value);
void playOrder(string order);
void init();
void output(int value);
void popFront();
void popBack();
deque<int> dq;
bool isFront =true;

int main(){
	int T, N;
	string order;
	scanf("%d", &T);

	for(int i =0; i < T; i++){
		isFront= true;
		cin >> order;
		scanf("%d", &N);
		input();
		playOrder(order);
	}
}

void input(){
	int numCount = 0;
	int digit = 100;
	int value = 0;
	char ch;
	while(1){
		 ch = getchar();
		 if(ch >= '0' && ch<='9'){
		 	value+=(ch-'0')*digit;
		 	digit/=10;
		 	numCount+=1;
		 }else if(ch == ',' || ch==']'){
		 	inputDeque(numCount, value);
		 	init(&digit, &value, &numCount);
		 	if(ch==']')
		 		break;
		 }
	}
}

void init(int *digit, int *value, int *numCount){
	*digit = 100;
	*value = 0;
	*numCount = 0;
}
void inputDeque(int numCount, int value){
	if(numCount == 1)
		dq.push_back(value/100);	
	else if(numCount == 2)
		dq.push_back(value/10);
	else if(numCount == 3)
		dq.push_back(value);
}



void playOrder(string order){
	for(int i = 0; i < order.size(); i++){
		if(order.at(i) == 'R')
			isFront = !isFront;
		else if(order.at(i) == 'D'){
			if(!dq.empty())
				isFront? popFront(): popBack();
			else{
				printf("error\n");
				return;
			}	
		}
	}
	printf("[");
	int value;
	while(!dq.empty()){
		if(isFront){
			value = dq.front();
			output(value);
			popFront();
		}else {
			value = dq.back();
			output(value);
			popBack();
		}
	}
	dq.clear();
	printf("]\n");
}

void popFront(){
	dq.pop_front();
}
void popBack(){
	dq.pop_back();
}

void output(int value){
	if(dq.size() == 1)
		printf("%d", value);	
	else
		printf("%d,", value);
}