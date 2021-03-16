#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
int testCase;

using namespace std;

void solve();
int toIndex(char num){
	return num - '0';
}

typedef struct TrieNode{
	bool isTerminal;
	TrieNode *children[11];

	TrieNode():isTerminal(false){
		memset(children, 0, sizeof(children));
	}

	~TrieNode(){
		for(int i = 0; i < 10; i++)
			if(children[i] != NULL)
				delete children[i];
	}

	void insert(char *words){
		if(*words == 0)
			isTerminal = true;
		else{
			int next = toIndex(*words);

			if(children[next] == NULL)
				children[next] = new TrieNode();

			children[next]->insert(words+1);
		}
	}

	int find(const char *words){
		int next = toIndex(*words);
		if(*(words+1) == 0){
			for(int i = 0; i < 10; i++)
				if(children[next]->children[i] != NULL){
					return 1;
				}

				return 0;
		}else
			return children[next]->find(words+1);
	}
}Trie;

int main(){
	scanf("%d", &testCase);

	for(int i = 0; i < testCase; i++){
		solve();
	}
}

void solve(){
	int N;
	char words[12];
	vector<string> wordsSet;
	scanf("%d", &N);

	TrieNode* root = new TrieNode();

	for(int i = 0; i < N; i++){
		scanf("%s", &words);
		root->insert(words);
		wordsSet.push_back(string(words));
	}

	sort(wordsSet.begin(), wordsSet.end());
	

	for(int i = 0; i < N; i++){
		if(root->find(wordsSet[i].c_str())){
			printf("NO\n");
			return ;
		}		
	}
	printf("YES\n");
}