#include <cstdio>
#include <map>
#include <string>
using namespace std;

map <string, string> parent;
map <string, int> friendCount;
int isFirst(string name);
void input();
string find(string a);
void merge(string a, string b);

int main(){
	int T;
	scanf("%d", &T);

	for(int testCase = 0; testCase < T; testCase++){
		input();
		parent.clear();
		friendCount.clear();
	}
}

void input(){
	int F;
	char friend1[25], friend2[25];
	scanf("%d", &F);

	for(int i = 0; i < F; i++){
		scanf("%s %s", &friend1, &friend2);
		string f1(friend1), f2(friend2);
		if(isFirst(f1)){
			parent[f1] = f1;
			friendCount[f1] = 1;
		}

		if(isFirst(f2)){
			parent[f2] = f2;
			friendCount[f2] = 1;
		}
		merge(f1, f2);
	}
}

int isFirst(string name){
	if(parent.find(name) == parent.end())
		return 1;
	else 
		return 0;
}


string find(string a){
	if(a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}

void merge(string a, string b){
	a = find(a), b = find(b);

	if(a == b){
		printf("%d\n", friendCount[a]);
		return;
	}

	parent[b] = a;
	friendCount[a]+=friendCount[b];

	printf("%d\n", friendCount[a]);
}