#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int maxinumSize;
int pi[1000002];
string order;

int getMax();

int main(){
	scanf("%d\n", &maxinumSize);
	getline(cin, order);
	printf("%d", maxinumSize - getMax());
}

int getMax(){
	int begin = 1, matched = 0;
	int orderSize = order.size();

	while(begin + matched < orderSize){
		if(order[begin + matched] == order[matched]){
			matched++;
			pi[begin + matched - 1] = matched;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}

	return pi[maxinumSize-1];
}