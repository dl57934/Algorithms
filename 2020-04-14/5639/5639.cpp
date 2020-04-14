#include <cstdio>

typedef struct tree{
	int left, right;
}Tree;

int root;
Tree suchTree[1000200];
void insert(int data);
void back(int index);
int main(){	
	int first = 1;
	int data;
	while(scanf("%d", &data) != -1){
		if(first == 1){
			root = data;
			first = 0;
		}else {
			insert(data);
		}
	}
	back(root);
}

void insert(int data){
	int index = root;
	for(;;){
		if(index < data){
			if(suchTree[index].right == 0){
				suchTree[index].right = data;
				break;
			}else{
				index = suchTree[index].right;
			}
		}else{
			if(suchTree[index].left == 0){
				suchTree[index].left = data;
				break;
			}else{
				index = suchTree[index].left;
			}
		}
	}
}


void back(int index){
	if(suchTree[index].left !=0 )
		back(suchTree[index].left);
	if(suchTree[index].right !=0 )
		back(suchTree[index].right);
	printf("%d\n", index);
}