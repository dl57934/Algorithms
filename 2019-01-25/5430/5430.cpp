#include <cstdio>
#include <string>
#include <deque>
#include <iostream>

using namespace std;

void inputArr();
void playOrder(string order);
void init();
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
		inputArr();
		playOrder(order);
	}
}

void inputArr(){
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
		 }else if(ch == ','){
		 	if(numCount == 1){
		 		dq.push_back(value/100);	
		 	}
		 	else if(numCount == 2){
		 		dq.push_back(value/10);
		 	}
		 	else if(numCount == 3){
		 		dq.push_back(value);
		 	}
		 	digit=100;
		 	value=0;
		 	numCount=0;
		 }else if(ch == ']'){
		 	if(numCount == 1){
		 		dq.push_back(value/100);	
		 	}
		 	else if(numCount == 2){
		 		dq.push_back(value/10);
		 	}
		 	else if(numCount == 3){
		 		dq.push_back(value);
		 	}
		 	digit=100;
		 	value=0;
		 	numCount=0;
		 	break;
		 }
	}
}

void playOrder(string order){

	for(int i = 0; i < order.size(); i++){
		if(order.at(i) == 'R')
			isFront = !isFront;
		else if (order.at(i) == 'D'){
			if(!dq.empty()){
				if(isFront){
					dq.pop_front();
				}else{
					dq.pop_back();
				}
			}else{
				printf("error\n");
				return;
			}
		}
	}
	printf("[");
	while(!dq.empty()){
		if(isFront){
			int value = dq.front();
		if(dq.size() == 1)
			printf("%d", value);	
		else
			printf("%d,", value);
		dq.pop_front();
		}else {
			int value = dq.back();
		if(dq.size() == 1)
			printf("%d", value);	
		else
			printf("%d,", value);
		dq.pop_back();
		}
	}
	dq.clear();
	printf("]\n");
}