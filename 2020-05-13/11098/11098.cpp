#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
	int n, p;
	scanf("%d", &n);
	for(int cs = 0; cs < n; cs++){
		vector <pair<int, string> > players;
		int money; char name[25];
		scanf("%d", &p);
		for(int person = 0; person < p; person++){
			scanf("%d %s", &money, &name);
			players.push_back(make_pair(money, name));
		}
		pair<int, string> test = *max_element(players.begin(), players.end());
		printf("%s\n", test.second.c_str());
	}
}