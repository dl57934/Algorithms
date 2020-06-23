#include <cstdio>

int G, P, airport[100002], airplane[100002];
void input();
void init();
int find(int a);
int merge(int a, int b);

int main(){
	input();
	int all = 0;
	for(int i = 2; i <= P; i++){
		if(!merge(airplane[i], airplane[i]-1)){
			printf("asdas%d", all);
			return 0;
		}else{
			all++;
		}
	}

	printf("%d", all);
}

void init(){
	for(int i = 1; i <= G; i++)
		airport[i] = i;
}

void input(){
	scanf("%d", &G);
	scanf("%d", &P);
	init();
	for(int i = 1; i <= P; i++)
		scanf("%d", &airplane[i]);
}

int find(int a){
	if(a == airport[a])
		return a;
	return airport[a] = find(airport[a]);
}

int merge(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b)
		return 0;

	airport[a] = b;
	return 1;
}