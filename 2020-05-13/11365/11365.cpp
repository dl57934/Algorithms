#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string order;
	while(1){
		getline(cin, order);
		if(order == "END")
			break;
		else {
			reverse(order.begin(), order.end());
			printf("%s\n", order.c_str());
		}
	}
}