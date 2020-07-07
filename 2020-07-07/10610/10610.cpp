#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char numbers[987643];

int main(){
	int sub = 0;
	int flag = 0;
	scanf("%s", &numbers);
	string order(numbers);

	for(int index = 0; index < order.size(); index++){
		sub+=order[index]-'0';
		if(order[index]-'0' == 0)
			flag = 1;
	}

	sort(order.begin(), order.end());
	reverse(order.begin(), order.end());
	if(sub%3==0 && flag){
		printf("%s", order.c_str());
	}else{
		printf("-1");
	}
}
