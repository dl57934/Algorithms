#include <iostream>
#include <cstdio>
using namespace std;

int arr[27][2];

void preorder(int index);
void midorder(int index);
void lastorder(int index);

int main(){
	int N;
	scanf("%d", &N);
	
	for(int i = 0; i < N; i++){
		char mid, left, right;
		cin >> mid >> left >> right;
		arr[mid-'A'][0] = left=='.' ? -1 : left-'A';
		arr[mid-'A'][1] = right=='.' ? -1 : right-'A';
	}
	preorder(0);
	printf("\n");
	midorder(0);
	printf("\n");
	lastorder(0);
}

void preorder(int index){
	if(index == -1)
		return ;
	printf("%c", char(index+'A'));
	preorder(arr[index][0]);
	preorder(arr[index][1]);

}

void midorder(int index){
	if(index == -1)
		return ;
	midorder(arr[index][0]);
	printf("%c", char(index+'A'));
	midorder(arr[index][1]);	
}

void lastorder(int index){
	if(index == -1)
		return ;
	lastorder(arr[index][0]);
	lastorder(arr[index][1]);
	printf("%c", char(index+'A'));

}