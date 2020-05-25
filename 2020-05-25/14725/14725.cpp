#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int N;
const int ALPHABET = 26;
int toNumber(char ch){return ch - 'A';}

struct TrieNode{
	TrieNode *children[ALPHABET];
	bool terminal;
	TrieNode() : terminal(false){
		memset(children, 0, sizeof(children));
	}
	~TrieNode(){
		for(int i = 0; i < ALPHABET; i++)
			if(children[i])
				free(children);
	}

	void insert(const char *key){
		if(*key == 0)
		    terminal = true;
		else{
			int next = toNumber(*key);
			if(children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->insert(key+1);
		}
	}

	void find(string words, int layer){
		for(int i = 0; i < ALPHABET; i++){
			if(children[i]){
				if(children[i]->terminal){
					for(int i = 0; i < layer; i++)
						cout << "--";
					cout << words + char(i + 'A') << '\n';
					words.clear();
					children[i]->find("", layer+1);
				}else{
					children[i]->find(words + char(i + 'A'), layer);
				}
				
			}
		}
		
	}
};

TrieNode *root = new TrieNode();

void input();

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();

	root->find("", 0);
}

void input(){
	cin >> N;
	string words;
	string wordsSet;
	int K;
	for(int i = 0; i < N; i++){
		cin >> K;
		for(int i = 0; i < K; i++){
			cin >> words;
			wordsSet+=words;
			root->insert(wordsSet.c_str());
		}
		wordsSet.clear();
	}
}

