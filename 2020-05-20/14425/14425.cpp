#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map <string, int> target;
int N, M;

void input();

int main(){
	input();
}

void input(){	
	string input;
	int count = 0;
	scanf("%d %d\n", &N, &M);
	for(int i = 0; i < N; i++){
		getline(cin, input);
		target[input] = 1;
	}
	
	for(int i = 0; i < M; i++){
		getline(cin, input);
		if(target[input] == 1)
			count++;
	}
	printf("%d", count);
}