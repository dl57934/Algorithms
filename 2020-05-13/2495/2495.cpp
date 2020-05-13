#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){

	for(int i = 0; i < 3; i++){
		int result = 1, midResult = 1;
		string order;
		getline(cin, order);

		for(int letter = 0; letter < 8; letter++){
			if(order[letter] == order[letter+1]){
				midResult+=1;
			}else{
				if(midResult > result)		
					result = midResult;
				midResult = 1;
			}
		}
		if(midResult > result)		
			result = midResult;
		printf("%d\n", result);
	}
}