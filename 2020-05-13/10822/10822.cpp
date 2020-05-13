#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string order;
	int sum = 0, num = 0;

	cin >> order;
	stringstream ss(order);

	while(ss>> num){
		sum+=num;
		ss.get();
	}

	printf("%d", sum);
}