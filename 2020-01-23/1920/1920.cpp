#include <stdio.h>
#include <algorithm>

using namespace std;

int originalArr[100003];
int findArr[100003];

int binarySearch(int start, int end, int findNumbers);

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &originalArr[i]);

	sort(originalArr, originalArr+N);
	int end = N;

	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf("%d", &findArr[i]);

	for(int i = 0; i < N; i++)
		if(binarySearch(0, end-1, findArr[i]))
			printf("1\n");
		else
			printf("0\n");
		
}

int binarySearch(int start, int end, int findNumbers){
	int mid = (start+end)/2;
	if(start > end)
		return 0;
	if(originalArr[mid] == findNumbers)
		return 1;
	else if(originalArr[mid] < findNumbers)
		return binarySearch(mid+1, end, findNumbers);
	else
		return binarySearch(start, mid-1, findNumbers);
}