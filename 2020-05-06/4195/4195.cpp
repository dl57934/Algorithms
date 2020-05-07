#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
int T, F;
map <string, string> parent;
map <string, int> size;
map <string, int> rank2;
void input();
string find(string name);
void merge(string name1, string name2);

int main(){
	input();
}

void input(){
	scanf("%d", &T);
	char name1[33], name2[33];
	for(int testCase = 0; testCase < T; testCase++){
		scanf("%d", &F);
		for(int fr = 0; fr < F; fr++){
			scanf("%s", &name1);
			scanf("%s", &name2);
			if(parent[name1] == "" && size[name1] == 0){
				parent[name1] = name1;
				size[name1]=1;
			}
			if(parent[name2] == "" && size[name2] == 0){
				parent[name2] = name2;
				size[name2] = 1;
			}
			merge(name1, name2);
			printf("%d\n", size[name1]);
		}
		parent.clear();
		size.clear();
		rank2.clear();
	}
}

string find(string name){
	if(name == parent[name])
		return name;

	return parent[name] = find(parent[name]);
}

void merge(string name1, string name2){
	name1 = find(name1);
	name2 = find(name2);

	if(name1 == name2) return;

	
	size[name2] += size[name1];
	
	parent[name1] = name2;
}