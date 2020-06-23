#include <cstdio>
#include <map>
#include <string>
using namespace std;

map<string, string> parent;
map<string, int> friendNumber;
void input();
string find(string name);
void merge(string name1, string name2);
int main(){
	input();
}



void input(){
	int testCase, F;
	scanf("%d", &testCase);
	char friend1[22], friend2[22];
	for(int cases = 0; cases < testCase; cases++){
		scanf("%d", &F);
		for(int friendCase = 0; friendCase < F; friendCase++){
			scanf("%s%s", &friend1, &friend2);
		 	string stringFriend1(friend1), stringFriend2(friend2);
			if(parent.find(stringFriend1) == parent.end()){
				parent[stringFriend1] = stringFriend1;
				friendNumber[stringFriend1] = 1;
			}
			if(parent.find(stringFriend2) == parent.end()){
				parent[stringFriend2] = stringFriend2;
				friendNumber[stringFriend2] = 1;
			}
			merge(stringFriend1, stringFriend2);
		}
		parent.clear();
		friendNumber.clear();
	}
}

string find(string name){
	if (parent[name] == name)
		return name;
	return parent[name] = find(parent[name]);
}

void merge(string name1, string name2){
	name1 = find(name1), name2 = find(name2);

	if(name1 == name2 ){
		printf("%d\n", friendNumber[name1]);		
		return;
	} 

	parent[name1] = name2;

	friendNumber[name2] += friendNumber[name1];

	printf("%d\n", friendNumber[name2]);
}