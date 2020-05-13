#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string result, order;
	getline(cin, order);
	result.push_back(order[0]);
	int findIndex = 0;
	for(;;){
		if(order.find('-', findIndex) == -1)
			break;
	 	int index = order.find('-', findIndex)+1;
	 	result.push_back(order[index]);
	 	findIndex = index;
	}

	printf("%s", result.c_str());
}