#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

int main(){
	string order;
	int T;
	string number;
	scanf("%d\n", &T);

	for(int cs = 0; cs < T; cs++){
		int result = 0;
		getline(cin, order);
		stringstream ss(order);
		while(ss >> number)
			result+=stoi(number);
		printf("%d\n", result);
	}
}

