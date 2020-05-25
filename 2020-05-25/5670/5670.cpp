#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TrieNode{
	map<char, TrieNode*> children;
	bool terminal;

	TrieNode():terminal(false){}

	void insert(const char *key){
		if(*key == 0)
			terminal=true;
		else{
			if(children.find(*key) == children.end()) 
				children[*key] = new TrieNode();
			children[*key]->insert(key+1);
		}
	}

	int find(const char *key, int count){
		if(*key == 0){
			return count;
		}else{
			if(children[*key]->terminal && children[*key]->children.size() >= 1){
				if(*(key+1) == 0)
					return children[*key]->find(key+1, count);
				else
					return children[*key]->find(key+1, count+1);
			}
			else if(children[*key]->children.size() <= 1){
				return children[*key]->find(key+1, count);
			}else{
				return children[*key]->find(key+1, count+1);
			}
		}
	}
};

void input();

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
}

void input(){
	int N;
	
	while(true){
		cin >> N;
		if(cin.eof() == true)
			break;
		TrieNode* root = new TrieNode();
		string words;
		int count = 0;
		vector <string> wordSet;
		for(int i = 0; i < N; i++){
			cin >> words;
			root->insert(words.c_str());
			wordSet.push_back(words);
		}

		for(auto word : wordSet)
			count+=root->find(word.c_str(), 1);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << (double)count/(double)N << '\n';
	}
}