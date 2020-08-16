#include <vector>
#include <iostream>
#include <string>

using namespace std;
vector<int> KMPSearch(string base, string hook);
vector<int> getPartialMatch(string N);

int main(){
	string base, hook;
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin, base);
	getline(cin, hook);

	vector<int> result = KMPSearch(base, hook);

	cout << result.size() << '\n';
	for (int a : result)
		cout << a + 1 << '\n';
}

vector<int> KMPSearch(string base, string hook){
	int baseSize = base.size();
	int hookSize = hook.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(hook);

	int begin = 0, matched = 0; // 첫 글자부터 검색을 시작한다.
	while(begin + matched < baseSize){
		if(matched < hookSize && base[begin+matched] == hook[matched]){
			matched++;
			if(matched == hookSize)
				ret.push_back(begin);
		}else{
			if(matched == 0) // matched가 0이면 다음 칸부터
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];	
			}
		}
	}

	return ret;
}


vector<int> getPartialMatch(string N){
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0; // begin이 0이면 자기 자신을 찾는다.

	while(begin + matched < m){
		if(N[begin + matched] == N[matched]){
			matched++;
			pi[begin+matched-1] = matched; 
		}else{
			if(matched == 0)
				++begin;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}

	return pi;
}