#include <cstdio>
#include <string>
#include <map>
#include <iostream>
using namespace std;

map <string, int>info;
string order[102];
string type[102];
int main(){
	int T, n;
	scanf("%d", &T);
	int result = 1;
	for(int i =0; i < T; i++){
		scanf("%d", &n);
		for(int i =0; i < n; i++){
			cin >> order[i] >> type[i];
			if(info.find(type[i]) == info.end())
				info[type[i]] = 1;
			else
				info[type[i]] += 1;
		}
		for (map<string,int>::iterator j= info.begin(); j != info.end(); j++)
			 result *= j->second+1;
			 
		cout << result-1<<endl;	
		info.clear();
		result = 1;
	}
}