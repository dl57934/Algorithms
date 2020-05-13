#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T, num;
	string order;
	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		scanf("%d", &num);
		cin >> order;
		printf("%s\n", (order.substr(0,num-1) + order.substr(num)).c_str());
	}
}