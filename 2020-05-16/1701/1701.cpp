#include <string>
#include <iostream>
#include <vector>
#include  <algorithm>
using namespace std;

string order;


int getLongestString(string order);

int main(){
	getline(cin, order);
	int maxNum = 0;
	for(int i = 0; i < order.size(); i++)
		maxNum = max(getLongestString(order.substr(i ,order.size())), maxNum);
	printf("%d", maxNum);
}

int getLongestString(string order){
	int begin = 1, matched = 0;
	int pi[987654] = {0, };
	int orderSize = order.size();
	while(matched + begin < orderSize){
		if(order[matched + begin] == order[matched]){
			matched++;
			pi[matched + begin - 1] = matched;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return *max_element(pi, pi + order.size());
}