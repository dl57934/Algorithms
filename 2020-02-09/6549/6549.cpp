#include <stdio.h>

int N;
long long map[100002];
void input();

int main(){
	while(1){
		input();
		if(N==0)
			break;

	}

}

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%lld", &map[i]);
}