#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> getPi(string hook);
vector<int> KMPSEARCH(string base, string hook);


int main(){
	string base, hook;
	getline(cin, base);
	getline(cin, hook);

	vector<int> result = KMPSEARCH(base, hook);
	printf("%d\n", result.size());
	for(auto ret : result)
		printf("%d\n", ret);
}

vector<int> getPi(string hook){
	int hookSize = hook.size();
	vector<int> pi(hookSize, 0);

	int begin = 1, matched = 0;

	while(begin + matched <= hookSize){
		if(hook[begin + matched] == hook[matched]){
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

	return pi;
}

vector<int> KMPSEARCH(string base, string hook){
	int begin = 0, matched = 0;
	vector <int> pi = getPi(hook);
	vector<int> result;
	int baseSize = base.size(), hookSize = hook.size();

	while(begin <= baseSize - hookSize){
		if(base[begin + matched] == hook[matched]){
			matched++;
			if(matched == hookSize) result.push_back(begin+1);
		}else{
			if(matched == 0)
				begin++;
			else{
				begin+=matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}

	return result;
}