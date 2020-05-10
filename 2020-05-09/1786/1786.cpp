#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector <int> result;
vector <int> pi(1000002, 0);
string base, hook;
void getPi();
void getSameWords();

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin, base);
	getline(cin, hook);

	getPi();
	getSameWords();

	cout << result.size() << '\n';
	for (int a : result)
		cout << a + 1 << '\n';
	
}

void getPi(){
	int hookSize = hook.size();
	int begin = 1, match = 0;

	while(begin + match < hookSize){
		if(hook[begin + match] == hook[match]){
			match++;
			pi[begin + match - 1] = match;
		}else{
			if(match == 0)
				begin++;
			else{
				begin += match - pi[match-1];
				match = pi[match-1];
			}
		}
	}
}

void getSameWords(){
	int baseSize = base.size();
	int hookSize = hook.size();

	int begin = 0, match = 0;

	while(begin <= (baseSize - hookSize)){
		if(hook[match] == base[begin + match]){
			match++;
			if(match == hookSize){
				result.push_back(begin);
			}
		}else{
			if(match == 0)
				begin++;
			else{
				begin += match - pi[match-1];
				match = pi[match-1];
			}
		}
	}
}




