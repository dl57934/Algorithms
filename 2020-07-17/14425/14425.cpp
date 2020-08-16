#include <cstdio>
#include <string.h>

const int ALPHABET = 26;
int toNumber(char a){return a - 'a';}

struct TrieNode{
	TrieNode* children[ALPHABET];
	bool terminal;
	TrieNode():terminal(false){
		memset(children, 0, sizeof(children));
	}

	~TrieNode(){
		for(int i = 0; i < ALPHABET; i++){
			if(children[i])
				delete(children[i]);
		}
	}

	void insert(const char* a){
		if(*a == 0)
			terminal = true;
		else{
			int next = toNumber(*a);
			if(children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(a+1);
		}
	}

	TrieNode* find(char* a){
		if(*a == 0 && terminal) return this;
		int next = toNumber(*a);
		if(children[next] == NULL) return NULL;
		return children[next]->find(a+1);
	}
};

int main(){
	int N, M, count = 0;
	char input[504];
	TrieNode *root = new TrieNode();
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++){
		scanf("%s", &input);
		root->insert(input);
	}

	for(int i = 0; i < M; i++){
		scanf("%s", &input);
		if(root->find(input) != NULL){
			count++;
		}
	}

	printf("%d", count);
}