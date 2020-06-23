#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<string, int> friendCount;
map<string, string> friendSet;
void input();
string find(string a);
void merge(string a, string b);

int main(){
	input();
}

void input(){
	int testCase = 0;
	int friendNum = 0;
	char name1[30], name2[30];
	scanf("%d", &testCase);
	for(int cas = 0; cas < testCase; cas++){
		friendCount.clear();
		scanf("%d", &friendNum);
		for(int i = 0; i < friendNum; i++){
			scanf("%s %s", &name1, &name2);
			if(friendSet.find(name1) == friendSet.end()){
				friendSet[name1] = name1;
				friendCount[name1] = 1;
			}

			if(friendSet.find(name2) == friendSet.end()){
				friendSet[name2] = name2;
				friendCount[name2] = 1;	
			}

			merge(name1, name2);
			printf("%d\n", friendCount[friendSet[name1]]);
		}
		friendCount.clear();
		friendSet.clear();

	}

}

string find(string a){
	if(a == friendSet[a])
		return a;
	return friendSet[a] = find(friendSet[a]);
}

void merge(string a, string b){
	a = find(a);
	b = find(b);

	if(a == b)
		return ;

	friendCount[a] += friendCount[b];

	friendSet[b] = a;
}