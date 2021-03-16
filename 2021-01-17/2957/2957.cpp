#include <cstdio>
#include <map>

using namespace std;

int count = 0;


int main(){
	int N;
	int num[300002];
	scanf("%d", &N);


	for(int i = 0; i < N; i++){
		scanf("%d", &num[i]);
	}


	BST* root = new BST(num[0]);
	printf("0\n");

	for(int i = 1; i < N; i++)
		root->insert(num[i]);
}