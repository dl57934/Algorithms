#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void getPi(string input);

int main(){
	string input;
	while(1){
		getline(cin, input);
		if(input == ".")
			break;
		getPi(input);
	}
}


void getPi(string input){
	int begin = 1, matched = 0;
	int size = input.size();
	vector <int> pi(size, 0);
	
	while(begin + matched < size){
		if(input[begin+matched] == input[matched]){
			matched++;
			pi[begin+matched-1] = matched;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin+=matched-pi[matched-1];
				matched=pi[matched-1];
			}
		}
	}
	
	if(size%(size-pi[size-1]) != 0){
		printf("1\n");	
	}else{
		printf("%d\n", size/(size-pi[size-1]));
	}
}