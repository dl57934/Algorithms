#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getPi(string hook);

int main(){
	string hook;
	getline(cin, hook);
	int maxValue = 0;
	for(int i = 0; i < hook.size(); i++){
		maxValue = max(maxValue, getPi(hook.substr(i, hook.size())));
	}

	printf("%d", maxValue);
}

int getPi(string hook){
	int hookSize = hook.size();
	vector<int> pi(hookSize, 0);
	int begin = 1, matched = 0;
	while(begin + matched < hookSize){
		if(hook[begin + matched] == hook[matched]){
			matched++;
			pi[begin+matched-1] = matched;
		}else{
			if(matched == 0)
				begin ++; 
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return *max_element(pi.begin(), pi.end());
}