#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int result = 0;
void getLongestLength(string hook){
	int hookSize = hook.size();
	int begin = 1, matched = 0;
	vector<int> pi(hookSize, 0);

	while(begin + matched <= hookSize){
		if(hook[matched] == hook[matched + begin]){
			matched++;
			pi[begin+matched-1] = matched;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	int maxNum = *max_element(pi.begin(), pi.end());
	if(result < maxNum){
		result = maxNum;
	}
}

int main(){
	string hook;
	getline(cin, hook);
	int hookSize = hook.size();
	for(int i = 0; i < hookSize; i++){
		getLongestLength(hook.substr(i, hookSize));
	}

	printf("%d", result);
}