#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

void solve();

int main(){
	int testCase;
	scanf("%d", &testCase);
	for(int i = 0; i < testCase; i++)
		solve();
}


void solve(){
	char letter[102];
	scanf("%s", &letter);
	int letterSize = strlen(letter);
	sort(letter, letter+letterSize);

	printf("%s\n", letter);
}