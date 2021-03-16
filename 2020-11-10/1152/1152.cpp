#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
	int count = 0;
	string str, temp;
	vector<string> vc;
 	getline(cin, str);

 	if(str[0] == ' ')
 		count = -1;
	stringstream ss(str);

	while(getline(ss, temp, ' '))
		vc.push_back(temp);
	
	cout << vc.size() + count ;
}