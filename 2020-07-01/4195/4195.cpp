#include <cstdio>
#include <map>
#include <string>
using namespace std;

int isFirst(string friendName);
map<string, int> friendCount;
map<string, string> parent;
int testCase;
string toString(char *friendName);
void input();
string find(string friendName);
void merge(string friend1, string friend2);

int main(){
	input();
}

void input(){
	int F;
	scanf("%d", &testCase);
	char friend1[33], friend2[33];
	for(int cs = 0; cs < testCase; cs++){
		scanf("%d", &F);
		for(int operation = 0; operation < F; operation++){
			scanf("%s %s", &friend1, &friend2);
			string friend1Name = toString(friend1);
			string friend2Name = toString(friend2);
			if(isFirst(friend1Name)){
				friendCount[friend1Name] = 1;
				parent[friend1Name] = friend1Name;
			}

			if(isFirst(friend2Name)){
				friendCount[friend2Name] = 1;
				parent[friend2Name] = friend2Name;
			}

			merge(friend1Name, friend2Name);
		}
		parent.clear(), friendCount.clear();
	}
}

int isFirst(string friendName){
	if(parent.find(friendName) == parent.end())
		return 1;
	return 0;
}

string find(string friendName){
	if(parent[friendName] == friendName)
		return friendName;
	return parent[friendName] = find(parent[friendName]);
}

void merge(string friend1, string friend2){
	friend1 = find(friend1), friend2 = find(friend2);
	if(friend1 == friend2){
		printf("%d\n", friendCount[friend1]);
		return;
	}

	parent[friend2] = friend1;
	friendCount[friend1] += friendCount[friend2];

	printf("%d\n", friendCount[friend1]);
}

string toString(char *friendName){
	return string(friendName);
}
