#include <cstdio>
#include <deque>
#include <queue>
#include <math.h>
using namespace std;

void input(int N, int M);
int calculate();
int isLeftCalculate();
int moveCount = 0;

deque<int> dq;
queue<int> qu;
int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	input(N, M);
	printf("%d", calculate());

}

void input(int N, int M){
	int value;
	for(int i = 0; i < M; i++){
		scanf("%d", &value);
		qu.push(value);
	}
	int startNumber = qu.front();
	for(int i=1; i<=N; i++)
		dq.push_back(i);	
}

int calculate(){
	while(!qu.empty()){
		if(isLeftCalculate()){
			while(qu.front() != dq.front()){
				dq.push_back(dq.front());
				dq.pop_front();
				moveCount+=1;
			}
		}else{
			while(qu.front() != dq.front()){
				dq.push_front(dq.back());
				dq.pop_back();
				moveCount+=1;
			}
		}
		dq.pop_front();
		qu.pop();
	}
	return moveCount;
}

int isLeftCalculate(){
	int position;
	for(int i = 0; i < dq.size(); i++){
		if(qu.front() == dq.at(i)){
			position = i+1;
			break;
		}
	}
	if(dq.size()/2+dq.size()%2 < position)
		return 0;
	return 1;
}