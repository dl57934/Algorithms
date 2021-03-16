#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string, int> mp;

int main(){
	int allTree = 0;
	while(true){
		string tree;
		getline(cin, tree);
		if(cin.eof() == true){
			break;
		}

		if(mp.find(tree) == mp.end()){
			mp[tree] = 1;
		}else{
			mp[tree] = mp[tree] + 1;
		}

		allTree+=1;
	}

	for(auto tree : mp){
		printf("%s %.4f\n", tree.first.c_str(), (float)tree.second/allTree*100);
	}
}