#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	char order[987654];
	scanf("%s", &order);
	string stringOrder(order);
	int flag = 0;
	int subSum = 0; 
	for(int i =0; i < stringOrder.size(); i++){
		if(stringOrder[i] == '0')
			flag = 1;
		subSum+= stringOrder[i] - '0';
	}

	if(flag == 1 && subSum%3 == 0){
		sort(stringOrder.begin(), stringOrder.end());
		reverse(stringOrder.begin(), stringOrder.end());
		printf("%s", stringOrder.c_str());
	}else{
		printf("-1");
	}
}