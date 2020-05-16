#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string feed, hook;
int frontSameBack[987654];
vector<int> result;

void getPI();
void getFindString();

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, feed);
	getline(cin, hook);

	getPI();
	getFindString();
	printf("%d\n", result.size());
	for(auto begin : result)
		printf("%d\n", begin+1);
}


void getPI(){
	int hookSize = hook.size();
	int begin = 1, matched = 0;

	while(begin + matched < hookSize){
		if(hook[begin + matched] == hook[matched]){
			matched++;
			frontSameBack[begin+matched-1] = matched;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - frontSameBack[matched-1];
				matched = frontSameBack[matched-1];
			}
		}
	}
}

void getFindString(){
	int feedSize = feed.size();
	int hookSize = hook.size();
	int begin = 0, matched = 0;

	while(begin<= (feedSize-hookSize)){
		if(feed[begin + matched] == hook[matched] && matched < hookSize){
			matched++;
			if(matched == hookSize) result.push_back(begin);
		}
		else{
			if(!matched)
				begin++;
			else{
				begin += matched - frontSameBack[matched-1];
				matched = frontSameBack[matched-1];
			}
		}
	}
}