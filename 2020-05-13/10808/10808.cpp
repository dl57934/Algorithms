#include <cstdio>
#include <string.h>
using namespace std;

int arr[30];

int main(){
	char order[105];
	scanf("%s", &order);

	int size = strlen(order);

	for(int i = 0; i < size; i++)
		arr[order[i]-'a']+=1;
	for(int i = 0; i < 26; i++)
		printf("%d ", arr[i]);
}