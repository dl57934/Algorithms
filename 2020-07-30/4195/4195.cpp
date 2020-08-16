#include <cstdio>
#include <map>
#include <string>
using namespace std;
map<string, string> parent;
map<string, int> friendCount;

void input();
int isExist(string name);
string find(string name);
void merge(string name1, string name2);


int main(){	
	int testCase;
	scanf("%d", &testCase);

	for(int i = 0; i < testCase; i++){
		input();
		parent.clear();
		friendCount.clear();
	}
}

void input(){
	int relation;
	char name1[23], name2[23];
	
	scanf("%d", &relation);

	for(int i = 0; i < relation; i++){
		scanf("%s %s", &name1, &name2);
		string strName1(name1), strName2(name2);	
		
		if(isExist(strName1)){
			parent[strName1] = strName1;
			friendCount[strName1] = 1;
		}

		if(isExist(strName2)){
			parent[strName2] = strName2;
			friendCount[strName2] = 1;
		}

		merge(strName1, strName2);
	}
}

int isExist(string name){
	if(parent.find(name) == parent.end())
		return 1;
	return 0;
}

string find(string name){
	if(parent[name] == name){
		return name;
	}

	return parent[name] = find(parent[name]);
}

void merge(string name1, string name2){
	name1 = find(name1), name2 = find(name2);

	if(name1 == name2){
		printf("%d\n", friendCount[name2]);
		return;
	}
	parent[name1] = name2;
	friendCount[name2] += friendCount[name1];

	printf("%d\n", friendCount[name2]);
}