#include <cstdio>

int N;
void input();
int tree[28][3];
void preorder(int num);
void inorder(int num);
void postorder(int num);

int main(){
	input();
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
}

void input(){
	char A, B, C;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf(" %c %c %c", &A, &B, &C);
		if(B == '.')
			tree[A-'A'][0] = -1;
		else
			tree[A-'A'][0] = B-'A';
		if(C == '.')
			tree[A-'A'][1] = -1;
		else
			tree[A-'A'][1] = C-'A';
	}
}

void preorder(int num){
	printf("%c", num +'A');

	if(tree[num][0] != -1)
		preorder(tree[num][0]);

	if(tree[num][1] != -1)
		preorder(tree[num][1]);
}
void inorder(int num){
	if(tree[num][0] != -1)
		inorder(tree[num][0]);
	printf("%c", num +'A');
	if(tree[num][1] != -1)
		inorder(tree[num][1]);
}
void postorder(int num){
	if(tree[num][0] != -1)
		postorder(tree[num][0]);
	if(tree[num][1] != -1)
		postorder(tree[num][1]);
	printf("%c", num +'A');
}