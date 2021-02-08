#include <cstdio>
#include <string>
#include <vector>
using namespace std;

void KMP(string base, string hook);
vector<int> getParition(string hook);

int main(){
	char base[1000002], hook[1000002];
	

	scanf("%s %s", &base, &hook);
	string S(base), P(hook);
	KMP(S, P);
}	


vector<int> getParition(string hook){
	int hookSize = hook.size();
	vector<int> vc(hookSize, 0);
	int base = 1, matched = 0;

	while(base + matched < hookSize){
		if(matched < hookSize && hook[base + matched] == hook[matched]){
			matched++;
			vc[matched+base -1 ] = matched;
		}else{
			if(matched == 0)
				base++;
			else{
				base+= matched - vc[matched-1];
				matched = vc[matched-1];
			}
		}
	}

	return vc;
}


void KMP(string base, string hook){
	vector<int> vc;
	int baseIndex = 0, hookIndex = 0;
	int baseSize = base.size(), hookSize = hook.size();
	vector<int> partion = getParition(hook);
	while(baseIndex <= baseSize-hookSize){
		if(hookIndex < hookSize && base[baseIndex+hookIndex] == hook[hookIndex]){
			hookIndex++;
			if(hookIndex == hookSize){
				vc.push_back(baseIndex);
			}
		}else{
			if(hookIndex == 0)
				baseIndex++;
			else{
				baseIndex += hookIndex - partion[hookIndex-1];
				hookIndex = partion[hookIndex-1];
			}
		}
	}

	if(vc.size() == 0)
		printf("0");
	else
		printf("1");
}