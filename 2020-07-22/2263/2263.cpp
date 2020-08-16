#include <cstdio>
#include <vector>

using namespace std;

int N;
int inorder[100002], postorder[100002];
int root[100002];

void input(){
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &inorder[i]);

	for(int i = 1; i <= N; i++)
		scanf("%d", &postorder[i]);
	for(int i = 1; i <= N; i++)
		root[inorder[i]] = i;
}

void getPreorder(int inStart, int inEnd, int postStart, int postEnd){
	if(inStart <= inEnd && postStart <= postEnd){
		int mid = root[postorder[postEnd]];
		printf("%d ", postorder[postEnd]);
		int leftLength = mid - inStart;
		getPreorder(inStart, mid-1, postStart, postStart + leftLength - 1);
		getPreorder(mid+1, inEnd, postStart + leftLength, postEnd-1);	
	}
}

int main(){
	input();
	getPreorder(1, N, 1, N);
}