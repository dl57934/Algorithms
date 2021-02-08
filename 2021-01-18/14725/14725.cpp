#include <cstdio>
#include <string.h>
#include <string>

using namespace std;

int toNumber(char a){return a - 'A';}
const int ALPHABET = 26;
struct TrieNode{
	bool terminal;
	int layer;
	TrieNode* children[ALPHABET];
	TrieNode():terminal(false){
		layer = -1;
		memset(children, 0, sizeof(children));
	}
	~TrieNode(){
		for(int i = 0; i < ALPHABET; i++)
			if(children[i] != NULL)
				delete(children[i]);
	}

	void insert(const char* key, int nowLayer){
		if(*key == 0){
			terminal = true;
		}
		else{
			int next = toNumber(*key);
			if(layer == -1)  layer = nowLayer;
			if(children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key+1, nowLayer);
		}
	}

	void allFind(int isStart, int isBase, string base){
		if(terminal)
			printf("\n");
		for(int i = 0; i < 26; i++){
			if(children[i] != NULL){
				if(isStart){
					for(int i = 0; i < layer; i++)
						printf("--");
					if(isBase != -1)
					printf("%s", base.c_str());		
				}
				printf("%c", char(i + 'A'));
				if(children[i]->terminal){
					if(layer  == children[i]->layer)
						children[i]->allFind(1, i, base+char(i + 'A'));
					else
						children[i]->allFind(1, -1, "");	
				}
				else
					children[i]->allFind(0, -1, base+char(i + 'A'));	
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
			root->insert(allFeed.c_str(), i);
		}
	}

	root->allFind(0, -1, "");
}