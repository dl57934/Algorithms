#include <cstdio>

int stick, antNumber;
int ant[1000002];

void input();

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
		input();
}

void input(){
	scanf("%d %d", &stick, &antNumber);
	for(int i = 0; i < antNumber; i++)
		scanf("%d", &ant[i]);
	
	for(int i = 0; i < antNumber; i++)
		
}