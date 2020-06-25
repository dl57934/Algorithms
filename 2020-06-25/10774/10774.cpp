#include <cstdio>
#include <map>

using namespace std;

int isValidUniform(char size, char compareSize);
char uniform[1000003];
char players[1000003];
int J, A;

void input();

int main(){
	input();
}

void input(){
	char size;
	int uniformNumber;
	int answer = 0;
	scanf("%d%d", &J, &A);

	for(int i = 1; i <= J; i++){
		scanf(" %c", &size);
		uniform[i] = size;
	}

	for(int i = 1; i <= A; i++){
		scanf(" %c %d", &size, &uniformNumber);
		if(isValidUniform(size, uniform[uniformNumber]) && players[uniformNumber] == '\0'){
			answer+=1;
			players[uniformNumber] = size;
		}
	}

	printf("%d", answer);
}

int isValidUniform(char size, char compareSize){
	if (size == 'L' && compareSize == 'L')
		return 1;
	else if(size == 'M' && (compareSize=='L' || compareSize=='M'))
		return 1;
	else if(size == 'S' && (compareSize=='S' || compareSize=='M' || compareSize=='L'))
		return 1;
	return 0;
}