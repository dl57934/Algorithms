#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map<string, int> order;
vector<string> orderSet;
int N, M; 
string orderWords;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		cin >> orderWords;
		order[orderWords] = 1;
	}

	for(int j = 0; j < M; j++){
		cin >> orderWords;
		if(order[orderWords] == 1){
			orderSet.push_back(orderWords);
		}
	}

	sort(orderSet.begin(), orderSet.end());

	cout<< orderSet.size() << "\n";
	for(string subOrder : orderSet){
		cout << subOrder << "\n";
	}
}