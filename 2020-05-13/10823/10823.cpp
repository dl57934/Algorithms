#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
	string allOrder;
	string order;

	int num = 0, sum = 0;
	
	while(getline(cin, order)){
		allOrder+=order;
	}
	stringstream ss(allOrder);
	while(ss >> num){
		sum+=num;
		ss.get();
	}
	printf("%d", sum);
}