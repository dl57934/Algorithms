#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int dcalculator(int nums);
int scalculator(int nums);
int lcalculator(int numbers);
int rcalculator(int numbers);
void makingGoal();

typedef pair<string, int> pi;



int origin, goal;
int T;

int main(){
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d %d", &origin, &goal);
		
		makingGoal();
	}
}



void makingGoal(){
	queue <pi> qu;
	int visit[1000200] = {0, };
	qu.push(make_pair("", origin));
	
	while(!qu.empty()){
		pi now = qu.front();
		string status = now.first;
		int numbers = now.second;
		qu.pop();
		if(numbers == goal){
			printf("%s\n", status.c_str());
			break;
		}

		int dNum = dcalculator(numbers*2);
		if(!visit[dNum]){			
			visit[dNum] = 1;
			qu.push(make_pair(status+'D', dNum));
		}

		
		int newNum = numbers==0? 9999: numbers-1;
		if(!visit[newNum]){
			visit[newNum] = 1;
			qu.push(make_pair(status+'S', newNum));	
		}

		int lIndex =  (numbers % 1000) * 10 + numbers / 1000;;
		if(!visit[lIndex]){
			visit[lIndex] = 1;
			qu.push(make_pair(status+'L', lIndex));
		}
		int rIndex = (numbers % 10) * 1000 + (numbers / 10);
		if(!visit[rIndex]){
			visit[rIndex] = 1;
			qu.push(make_pair(status+'R', rIndex));
		}
	}
}

int dcalculator(int nums){
	return nums%10000;
}

int scalculator(int nums){
	return nums;
}

int lcalculator(int numbers){
	int thou = numbers/1000;
	numbers-=thou*1000;
	int hund = (numbers%1000)/100;
	numbers-=hund*100;
	int ten = numbers/10; 
	int one = numbers%10;
	
	return hund*1000 + ten * 100 + one * 10 + thou;
}

int rcalculator(int numbers){
	int thou = numbers/1000;
	numbers-=thou*1000;
	int hund = (numbers%1000)/100;
	numbers-=hund*100;
	int ten = numbers/10; 
	int one = numbers%10;

	return one*1000 + thou * 100 + hund * 10 + ten;
}