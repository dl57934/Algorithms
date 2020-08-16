#include <cstdio>
#include <string.h>
#include <string>

using namespace std;

int toNumber(char a){return a - 'A';}
const int ALPHABET = 26;
struct TrieNode{
	bool terminal;
	TrieNode* children[ALPHABET];
	TrieNode():terminal(false){
		memset(children, 0, sizeof(children));
	}
	~TrieNode(){
		for(int i = 0; i < ALPHABET; i++)
			if(children[i] != NULL)
				delete(children[i]);
	}

	void insert(const char* key){
		if(*key == 0)
			terminal = true;
		else{
			int next = toNumber(*key);
			if(children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key+1);
		}
	}

	void allFind(int rank, int isStart){
		if(terminal) 
			printf("\n");
		for(int i = 0; i < 26; i++){
			

			if(children[i] != NULL){
				if(isStart)
					for(int i = 0; i < rank; i++)
						printf("--");
				printf("%c", char(i + 'A'));
				if(children[i]->terminal)
					children[i]->allFind(rank+1, 1);	
				else
					children[i]->allFind(rank, 0);	
			}
		}
	}
};

int main(){
	int N, base;
	char feed[100];
	TrieNode *root = new TrieNode();
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &base);
		string allFeed = "";
		for(int i = 0; i < base; i++){
			scanf("%s", &feed);
			allFeed+=feed;
			root->insert(allFeed.c_str());
		}
	}

	root->allFind(0, 0);
}