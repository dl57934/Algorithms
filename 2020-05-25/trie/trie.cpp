#include <string.h>
#include <cstdio>

const int ALPHABETS = 26;
int toNumber(char ch) {return ch - 'a';}

struct TrieNode {
	TrieNode* children[ALPHABETS];

	bool terminal;
	TrieNode() : terminal(false){
		memset(children, 0, sizeof(children));
	}

	~TrieNode(){
		for(int i = 0; i < ALPHABETS; i++)
			if(children[i])
				delete children[i];
	}

	void insert(char* key){
		if(*key == 0)
			terminal = true;
		else{
			int next = toNumber(*key);
			if(children[next] == NULL)
				children[next] = new TrieNode();

			children[next]->insert(key+1);
		}
	}

	TrieNode* find(char* key){
		if(*key == 0 && terminal)return this;
		int next = toNumber(*key);
		if(children[next] == NULL) return NULL;
		return children[next]->find(key+1);
	}
};


int main(){
	int N, M, find = 0;	
	char words[504];
	TrieNode* root = new TrieNode();
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++){
		scanf("%s", &words);
		root->insert(words);
	}

	for(int i = 0; i < M; i++){
		scanf("%s", &words);
		if(root->find(words) != NULL){
			find++;
		}
	}

	printf("%d", find);
	
}













