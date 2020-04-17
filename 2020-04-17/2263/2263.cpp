#include <cstdio>

int n;
int postOrder[100002];
int inOrder[100002];
int appearence[100002];

void push();
void getPreorder(int inStart, int inEnd, int postStart, int postEnd);

int main(){
	push();
	getPreorder(1, n, 1, n);
}


void push(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &inOrder[i]);
		appearence[inOrder[i]] = i;
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", &postOrder[i]);
}

void getPreorder(int inStart, int inEnd, int postStart, int postEnd){
	if(inStart > inEnd || postStart > postEnd)
		return;
	int rootIndex = appearence[postOrder[postEnd]];
	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;
	printf("%d ", postOrder[postEnd]);
	getPreorder(inStart, rootIndex-1, postStart, postStart+leftSize-1);
	getPreorder(rootIndex+1, inEnd, postStart+leftSize, postEnd-1);
}