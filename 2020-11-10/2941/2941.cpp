#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	string order;
	
	getline(cin, order);
	int count = order.size();
	for(int i = 0; i < order.size(); i++){
		if(order[i] == 'c' || order[i] == 's' || order[i] == 'z'){ 
			if(order[i+1] == '=' || order[i+1] == '-'){
				count-=1;
				i+=1;
			}
		}else if(order[i] == 'd'){
			if(order[i+1] == '-'){
				count-=1;
				i+=1;
			}else if(order[i+1] == 'z' && order[i+2] == '='){
				count-=2;
				i+=2;
			}
		}
		else if(order[i] == 'l' || order[i] == 'n'){
			if(order[i+1] == 'j'){
				count-=1;
				i+=1;
			}
		}
	}

	printf("%d", count);
}