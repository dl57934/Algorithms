#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

long long GCD(long long a, long long b){
	if( b == 0)
		return a;
	else 
		return GCD(b, a%b);
}

int main(){
	string order;
	getline(cin, order);

	stringstream ss(order);

	long long first, second;

	ss >> first;
	ss.get();
	ss >> second;

	long long gcd = GCD(first, second);
	printf("%lld:%lld", first/gcd, second/gcd);
}