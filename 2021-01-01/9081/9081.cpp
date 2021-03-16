#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;
void solve();
char subResult[103];

int main(){
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		solve();
	}
}



void solve(){
	char words[103], copy[103];
	int visit[102] = {0, };
	int flag = 0;

	scanf("%s", &words);
	int size = strlen(words);
	for(int i = 0; i < size; i++){
		strcpy(copy, words);
		sort(copy + i, copy+size, greater<char>());
		printf("%s\n", copy);
	}
}