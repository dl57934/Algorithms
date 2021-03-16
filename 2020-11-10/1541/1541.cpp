#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string order;

	getline(cin, order);
	int num = 0, sum = 0, subSum = 0, isMinus = 0;
	for(int i = 0; i < order.size(); i++){
		if(order[i] == '-'){
			if(isMinus == 0){
				sum += num + subSum;
				isMinus = 1;
			}else
				sum -= subSum + num;
			subSum = 0, num = 0;
		}else if(order[i] == '+'){
			subSum+=num;
			num = 0;
		}else{
			num*=10;
			num += order[i] - '0';
		}
	}

	if(isMinus){
		subSum+=num;
		sum -= subSum;
	}else{
		subSum+=num;
		sum += subSum;
	}
	

	printf("%d", sum);
}

