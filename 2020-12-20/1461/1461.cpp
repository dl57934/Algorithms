#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <vector> 

using namespace std;


int main(){
	int N, M;
	vector<int> leftBook, rightBook;
	int bookLocation, maxLocation = 0;
	int save = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%d", &bookLocation);
		if(bookLocation < 0)
			leftBook.push_back(abs(bookLocation));
		else
			rightBook.push_back(bookLocation);
		if(maxLocation < abs(bookLocation)){
			maxLocation = abs(bookLocation);
		}
	}

	sort(leftBook.begin(), leftBook.end(), greater<int>());
	sort(rightBook.begin(), rightBook.end(), greater<int>());
	int rightIndex = 0, leftIndex = 0;

	while(rightIndex < rightBook.size()){
		save += rightBook[rightIndex] * 2;
		rightIndex += M;
	}

	while(leftIndex < leftBook.size()){
		save += leftBook[leftIndex] * 2;
		leftIndex += M;
	}	

	printf("%d",save - maxLocation);
}