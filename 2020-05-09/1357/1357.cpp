#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	string num1, num2;

	cin >> num1 >> num2;
	reverse(num2.begin(), num2.end());
	reverse(num1.begin(), num1.end());
	string result = to_string(stoi(num1) + stoi(num2));
	reverse(result.begin(), result.end());
	cout <<  stoi(result);
}