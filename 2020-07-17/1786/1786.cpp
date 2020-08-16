#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

vector<int> KMPSearch(string base, string hook);
vector<int> getPi(string hook);

int main(){
	string base, hook;
	getline(cin, base);
	getline(cin, hook);
	vector<int> result = KMPSearch(base, hook);
	printf("%d\n", result.size());

	for(auto begin : result){
		printf("%d\n", begin+1);
	}
}

vector<int> KMPSearch(string base, string hook){
	vector<int> pi = getPi(hook);
	vector<int> result;
	int begin = 0, matched = 0;
	int baseSize = base.size(), hookSize = hook.size();

	while(begin <= baseSize-hookSize){
		if(base[begin + matched] == hook[matched]){
			matched++;
			if(hookSize == matched) result.push_back(begin);
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

vector<int> getPi(string hook){
	int hookSize = hook.size();
	vector<int> pi(hookSize, 0);

	int begin = 1, matched = 0;


	while(begin + matched < hookSize){
		if(hook[begin + matched] == hook[matched]){
			matched++;
			pi[begin + matched - 1] = matched;
		}else {
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