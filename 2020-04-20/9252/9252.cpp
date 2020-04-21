#include <cstdio>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int lengthBoard[1003][1003];
char input1[1002], input2[1002];
int size1, size2;
stack<int> st;
int findLength;
void dp();
void getString();

int main(){
	scanf("%s %s", &input1, &input2);
	size1 = strlen(input1);
	size2 = strlen(input2);
	dp();
	findLength = lengthBoard[size1][size2];
	printf("%d\n", findLength);
	getString();
	while(!st.empty()){
		printf("%c", st.top());
		st.pop();
	}
}

void dp(){
	for(int y = 1; y <= size1; y++){
		for(int x = 1; x <= size2; x++){
			if(input1[y-1] == input2[x-1]){
				lengthBoard[y][x] = lengthBoard[y-1][x-1] + 1;
			}else{
				lengthBoard[y][x] = max(lengthBoard[y-1][x], lengthBoard[y][x-1]);
			}
		}
	}
}

void getString(){
	for(int y = size1; y >= 1; y--){
		for(int x = 1; x <= size2; x++){
			if(findLength == lengthBoard[y][x] && input1[y-1] == input2[x-1]){
				st.push(input1[y-1]);
				findLength-=1;
				break;
			}
		}
	}
}