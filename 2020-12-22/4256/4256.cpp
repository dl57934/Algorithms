#include <cstdio>

int preorder[1002], inorder[1002];
int root[1002];

void postOrder(int start, int end, int preStart, int preEnd);

int main(){
	int T, size;
	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		scanf("%d", &size);

		for(int j = 0; j < size; j++)
			scanf("%d", &preorder[j]);
		
		for(int j = 0; j < size; j++)
			scanf("%d", &inorder[j]);

		for(int j = 0; j < size; j++)
			root[inorder[j]] = j;

		postOrder(0, size-1, 0, size - 1);
		printf("\n");
	}

}

void postOrder(int start, int end, int preStart, int preEnd){
	int rootIndex = root[preorder[preStart]];
	int leftDistance = rootIndex - start;
	int rightDistance = end - rootIndex;

	if(leftDistance > 0)
		postOrder(start, rootIndex - 1, preStart + 1, preStart + leftDistance);

	if(rightDistance > 0)
		postOrder(rootIndex+1, end, preStart + leftDistance + 1, preEnd);

	printf("%d ", inorder[rootIndex]);
}

// 1
// 8
// 3 6 5 4 8 7 1 2
// 5 6 8 4 3 1 2 7