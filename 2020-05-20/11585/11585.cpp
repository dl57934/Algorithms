#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> pi(4000002, 0);
string hook, target;

void getPi();
int getSameString(string doubleTarget);
int getGCD(int a, int b);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	
	for(int i = 0; i < N; i++){
		char a;
		cin >> a;
		target.push_back(a);
	}
	for(int i = 0; i < N; i++){
		char a;
		cin >> a;
		hook.push_back(a);	
	}
	
	getPi();
	int count = getSameString((target + target).substr(0, 2*N-1));
	int gcd = getGCD(count, N);

	printf("%d/%d", (count/gcd), (N/gcd));
}

void getPi(){
	int begin = 1, matched = 0;
	int hookSize = hook.size();
	while(begin + matched < hookSize){
		if(hook[matched] == hook[begin + matched]){
			matched++;
			pi[begin + matched - 1] = matched;
		}else{
			if(matched==0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
}

int getSameString(string doubleTarget){
	int begin = 0, matched = 0;
	int ans = 0;
	int hookSize = hook.size();
	int doubleTargetSize = doubleTarget.size();

	while(begin <= (doubleTargetSize - hookSize)){
		if(doubleTarget[begin + matched] == hook[matched] && matched < hookSize){
			matched++;
			
			if(matched == hookSize) ans++;
		}else{
			if(matched == 0)
				begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return ans;
}

int getGCD(int a, int b){
	if(b == 0){
		return a;
	}
	return getGCD(b, a%b);
}