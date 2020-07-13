#include <cstdio>

int T, N;
int grade[100002];

void input();

int main(){
	scanf("%d", &T);

	for(int cs = 0; cs < T; cs++){
		input();
		int people = N;
		int base = grade[1];
		for(int person = 2; person <= N; person++){
			if(base < grade[person]){
				people--;
			}else{
				base = grade[person];
			}
		}
		printf("%d\n", people);
	}
}

void input(){
	scanf("%d", &N);
	int sub;
	for(int person = 1; person <= N; person++){
		scanf("%d", &sub);
		scanf("%d", &grade[sub]);
	}
}