#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int L;
int getMaxAD(string order);

int main(){
	
	string order;
	scanf("%d ", &L);
	getline(cin, order);
	printf("%d", L-getMaxAD(order));
}


int getMaxAD(string order){
	int orderSize = order.size();
	vector<int> pi(orderSize, 0);
	int begin = 1, matched = 0;

	while(begin + matched < orderSize){
		if(order[begin + matched] == order[matched]){
			matched++;
			pi[begin+matched-1] = matched;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin+=matched-pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}

	return pi[L-1];
}