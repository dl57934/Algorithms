#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getpi(string hook);
vector<int> KMP(string base, string hook);

int main(){
	string base, hook;
	getline(cin, base);
	getline(cin, hook);
	vector<int> result = KMP(base, hook);

	printf("%d\n", result.size());
	for(auto begin : result)
		printf("%d\n", begin);
}

vector<int> getpi(string hook){
	int hookSize = hook.size();
	int start = 1, matched = 0;
	vector<int> pi(hookSize, 0);

	while(start + matched <= hookSize){
		if(hook[matched] == hook[start + matched]){
			matched++;
			pi[start + matched - 1] = matched;
		}else{
			if(matched == 0)
				start++;
			else{
				start += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

vector<int> KMP(string base, string hook){
	int hookSize = hook.size(), baseSize = base.size();
	int start = 0, matched = 0;
	vector<int> result;
	vector<int> pi = getpi(hook);
	while(start + hookSize <= baseSize){
		if(base[start + matched] == hook[matched]){
			matched++;
			if(matched == hookSize) result.push_back(start+1);
		}
		else{
			if(matched == 0)
				start++;
			else{
				start += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return result;
}