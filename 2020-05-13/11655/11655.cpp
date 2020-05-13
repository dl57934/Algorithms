#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
	string order;
	getline(cin, order);
	
	for(char letter : order){
		if((letter <= 'z' && letter >= 'a') || (letter <= 'Z' && letter >= 'A')){
			if((letter <= 'z' && letter >= 'a')){
				if(letter+13 > 'z'){
					letter = 'a' + (letter+13) - 'z' - 1;
				}else
				letter+=13;
			}else if((letter <= 'Z' && letter >= 'A')){
				if(letter+13 > 'Z'){
					letter = 'A' + (letter+13) - 'Z' - 1;
				}else
				letter+=13;
			}
			printf("%c", letter);
		}else
			printf("%c", letter);
	}
}