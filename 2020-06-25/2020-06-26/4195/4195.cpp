#include <cstdio>
#include <map>
#include <string>

using namespace std;
map<string, int> friendCount;
map<string, string> parent;

void input();
string find(string name);
void isFirstData(string name);
void dataInit(string name);
void merge(string name1, string name2);

int main(){
	input();
}

void input(){
	int testCase, F;
	char name1[32], name2[32];
	scanf("%d", &testCase);
	for(int i = 0; i < testCase; i++){
		scanf("%d", &F);
		for(int userIndex = 0; userIndex < F; userIndex++){
			scanf("%s%s", &name1, &name2); 
			string stringName1 = string(name1);
			string stringName2 = string(name2);
			isFirstData(stringName1), isFirstData(stringName2);
			merge(stringName1, stringName2);
		}
		friendCount.clear();
		parent.clear();
	}

}


string find(string name){
	if(name == parent[name])
		return name;
	return parent[name] = find(parent[name]);
}

void isFirstData(string name){
	if(parent.find(name) == parent.end()){
		dataInit(name);
	}
}

void dataInit(string name){
	friendCount[name] = 1;
	parent[name] = name;
}

void merge(string name1, string name2){
	name1 = find(name1), name2 = find(name2);

	if(name1 == name2){
		printf("%d\n", friendCount[name1]);
		return ;
	}

	parent[name1] = name2;
	friendCount[name2] += friendCount[name1];
	printf("%d\n", friendCount[name2]);
}