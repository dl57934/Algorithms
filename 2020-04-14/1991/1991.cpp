#include <cstdio>

char tree[29][3];
int N;

void input();
void front(int point);
void back(int point);
void mid(int point);

int main(){
	input();
	
	front(1);
	printf("\n");
	mid(1);
	printf("\n");
	back(1);
}
void input(){
	scanf("%d", &N);
	char mid, left, right;
	for(int i = 0; i < N; i++){
		fflush(stdin);
		scanf(" %c %c %c", &mid, &left, &right);
		tree[mid-64][2] = right;
		tree[mid-64][1] = left; 
	}
}

void front(int point){
	if(point==-18)
		return;
	printf("%c", point + 64);
	front(tree[point][1]-64);
	front(tree[point][2]-64);
}
void back(int point){
	if(point==-18)
		return ;
	back(tree[point][1]-64);
	back(tree[point][2]-64);
	printf("%c", point + 64);
	
}
void mid(int point){
	if(point==-18)
		return;
	mid(tree[point][1]-64);
	printf("%c", point+64);
	mid(tree[point][2]-64);
	
}



