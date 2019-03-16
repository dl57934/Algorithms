#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string arr[102][102]={"0",};

string ncm(int n, int m);

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	cout << ncm(n, m) << endl;
}

string ncm(int n, int m){
	if (n==m || m== 0)
		return "1";
	else {
		if(arr[n][m] =="0")
			arr[n][m] = to_string(stoi(ncm(n-1, m-1)) + stoi(ncm(n-1, m)));
		return stoi(arr[n][m]);
	}
}