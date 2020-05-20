#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector <string> order(60);

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> order[i];
	
	int size = order[0].size();
	string copy2 = order[0];
	for(int maxi = 0; maxi < size; maxi++){
		for(int i = 1; i < N; i++){
			if(order[i-1][maxi] != order[i][maxi]){
				copy2[maxi] = '?';
				break;
			}
		}
	}

	
	
	cout << copy2 << endl;
}

