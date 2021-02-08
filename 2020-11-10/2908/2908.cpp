#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string swap(string str);
int changeNum(string str);

int main(){
	vector <string> vc;
	string order, temp;
	getline(cin, order);
	stringstream ss(order);

	while(getline(ss, temp, ' '))
		vc.push_back(temp);
	
	for(int i = 0; i < 2; i++)
		vc[i] = swap(vc[i]);

	if(changeNum(vc[0]) < changeNum(vc[1]))
		cout << vc[1];
	else
		cout << vc[0];
}

string swap(string str){
	char temp = str[0];
	str[0] = str[2];
	str[2] = temp;
	return str;
}

int changeNum(string str){
	return atoi(str.c_str());
}