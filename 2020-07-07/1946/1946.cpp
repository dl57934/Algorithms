#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct user{
	int paper;
	int interview;
}user;
int N;
int users[100002];

void input();
void findPerson();

int main(){
	int testCase;
	scanf("%d", &testCase);

	for(int cs = 0; cs < testCase; cs++){
		input();
		findPerson();
	}
}

void input(){
	scanf("%d", &N);
	int paper, interview;
	for(int i = 0; i < N; i++){
		scanf("%d %d", &paper, &interview);
		users[paper] = interview;
	}
}

void findPerson(){
	int all = N;
	int compareSize = users[1];
	for(int person = 2; person <= N; person++){
		if(compareSize < users[person]){
			all-=1;
		}else if(compareSize > users[person]){
			compareSize = users[person];
		}
	}

	printf("%d\n", all);
}