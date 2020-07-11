#include <cstdio>

int T, N, member[100003];
void input();

int main(){
	input();
}

void input(){
	int interview, paper;
	scanf("%d", &T);

	for(int cs = 0; cs < T; cs++){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d %d", &paper, &interview);
			member[paper] = interview;
		}
		int base = member[1];
		int members = N;
		for(int i = 2; i <= N; i++){
			if(base > member[i]){
				base = member[i]; 
			}else if(base < member[i]){
				members--;
			}
		}
		printf("%d\n", members);
	}
}