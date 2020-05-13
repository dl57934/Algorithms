#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

string order;
vector<string> orderSet;
int main(){
	getline(cin, order);
	for(int i = 0; i < order.size();i++){
		orderSet.push_back(order.substr(i));
	}

	sort(orderSet.begin(), orderSet.end());

	for(auto str:orderSet)
		printf("%s\n", str.c_str());
}