#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> result;

int main(){
	string order;
	int index = 1;
	while(getline(cin, order)){
		if( order.find("FBI") != -1){
			result.push_back(index);
		}
		index++;
	}
	if(result.size() == 0){
		printf("HE GOT AWAY!");
		return 0;
	}

	for(auto res : result)
		printf("%d ", res);
}