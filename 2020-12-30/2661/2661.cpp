#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

void backTrack(int limit);
int check(int size);
int N;
vector<string> result;
string sub;

int main(){
	scanf("%d", &N);
	
	for(int i = 1; i <= 82; i++)
		sub.push_back('1');

	backTrack(1);
}

void backTrack(int limit){

	if(limit == N+1){
		printf("%s",sub.substr(0, N).c_str());
		exit(0);
	}

	for(int i = 1; i <= 3; i++){
			if(limit >= 2){
				if(sub[limit-2] != i){
					sub[limit-1] = i + '0';
					if(check(limit))
						backTrack(limit+1);
				}
			}else if(limit == 1){
				sub[limit-1] = i + '0';
				backTrack(limit+1);
			}
	}
}


int check(int size){
	int flag = 0;
	for(int start = 0; start < size; start++){
		if((size-start) % 2 == 0){
			int mid = (size-start)/2;
			if(sub.substr(start, mid).compare(sub.substr(start + mid, mid)) == 0){
				return 0;
			}
		}
	}

	return 1;
}