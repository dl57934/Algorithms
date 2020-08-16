#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> KMP(string base, string hook);
vector<int> getpi(string hook);

int main(){
	string base, hook;
	getline(cin, base);
	getline(cin, hook);
	vector<int> result = KMP(base, hook);
	printf("%d\n", result.size());
	for(auto count :result)
		printf("%d\n", count);
}

vector<int> getpi(string hook){
	int hookSize = hook.size();
	vector<int> pi(hookSize, 0);

	int begin = 1, matched = 0;	
	while(begin + matched <= hookSize){
		if(hook[begin+matched] == hook[matched]){
			matched++;
			pi[begin + matched - 1] = matched;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}

	return pi;
}

vector<int> KMP(string base, string hook){
	vector<int> pi = getpi(hook);
	int hookSize = hook.size();
	int baseSize = base.size();
	int begin = 0, matched = 0;
	vector<int> result;

	while(begin + hookSize <= baseSize){
		if(base[begin+matched] == hook[matched]){
			matched++;
			if(matched == hookSize) result.push_back(begin+1);
		}else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return result;
}
