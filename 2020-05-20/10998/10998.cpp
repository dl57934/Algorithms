#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string words;
string copy2;
int main(){
 getline(cin, words);
	copy2 = words;
 reverse(copy2.begin(), copy2.end());
 if(words == copy2)
 	printf("1");
 else
 	printf("0");
}