#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(){
	string order1, mul, order2;
	cin >> order1 >> mul >> order2;

	if(mul == "*"){
		for(int i = 0; i < order2.size()-1; i++)
			order1.push_back('0');
		printf("%s", order1.c_str());
	}else{
		if(order1.size() > order2.size()){
			if(order1[order1.size() - order2.size()] == '0')
				order1[order1.size() - order2.size()] = '1';
			else 
				order1[order1.size() - order2.size()] = '2';
			printf("%s", order1.c_str());
		}else{
			if(order2[order2.size() - order1.size()] == '0')
				order2[order2.size() - order1.size()] = '1';
			else 
				order2[order2.size() - order1.size()] = '2';
			printf("%s", order2.c_str());
		}
	}
}