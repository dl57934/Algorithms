#include <cstdio>

int inorder[100002];
int postorder[100002];
int appearence[100002];
int N;

void input();
int binarySearch(int start, int end, int findNum);
void getRoot(int inStart, int inEnd, int poStart, int poEnd);


int main(){
	input();
	getRoot(1, N, 1, N);
}


void getRoot(int inStart, int inEnd, int poStart, int poEnd){
	if(inStart > inEnd || poStart > poEnd){
		return ;
	}

	int root = postorder[poEnd];
	printf("%d ", root);

	int rootIndex = appearence[root];
	int leftSize = rootIndex-inStart;
	int rightSize = poEnd - rootIndex;
	
	getRoot(inStart, rootIndex-1, poStart, poStart+leftSize-1);
	getRoot(rootIndex+1, inEnd, poStart+leftSize, poEnd-1);
}

void input(){
	scanf("%d", &N);
	for(int k = 0; k < 2; k++){
		for(int i = 1; i <= N; i++){
			if(k == 0)
				scanf("%d", &inorder[i]);
			else 
				scanf("%d", &postorder[i]);
		}
	}	
	for(int i = 1; i <= N; i++)
		appearence[inorder[i]] = i;
}

// 15
// 8 4 9 2 10 5 11 1 12 6 13 3 14 7 15
// 8 9 4 10 11 5 2 12 13 6 14 15 7 3 1


// 7 
// 4 2 5 1 6 3 7
// 4 5 2 6 7 3 1
