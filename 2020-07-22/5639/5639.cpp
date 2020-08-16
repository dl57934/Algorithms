#include <cstdio>
#include <algorithm>

using namespace std;

int preorder[1000002], size;

void input(){
	int num;
	while(scanf("%d", &num) != -1){
		preorder[size++] = num;
	}
}

void getPostOrder(int start, int end){
	if(start  < end){		
		int mid = upper_bound(preorder + start+1, preorder+end, preorder[start]) - preorder;
		getPostOrder(start+1, mid);
		getPostOrder(mid, end);
		printf("%d\n", preorder[start]);
	}
}


int main(){
	input();
	getPostOrder(0, size);
}