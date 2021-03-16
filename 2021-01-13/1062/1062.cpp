#include <cstdio>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

int visit[27];
int backTrackingVisit[27];
int inputChar[27];
long long mask[52];
vector<char> vc;
vector<string> input;
void back(int limit);
int result;

int N, K;

int main(){
	char letter[20];
	scanf("%d %d", &N, &K);	

	for(int i = 0; i < N; i++){
		scanf("%s", &letter);
		int size = strlen(letter);
		for(int j = 0; j < size; j++){
			visit[letter[j] - 'a']=1;
			if(letter[j] != 'a' && letter[j] != 'n' && letter[j] != 'c' && letter[j] != 'i' && letter[j] != 't'){
				long long bit = 1 << (letter[j] - 'a');
				mask[i] |= bit;
			}
		}
		input.push_back(string(letter));
	}

	K-=5;

	if( K < 0){
		printf("0");
		return 0;
	}




	for(int i = 0; i < 26; i++){
		if('a' + i != 'a' && 'a' + i != 'n' && 'a' + i != 'c' && 'a' + i != 'i' && 'a' + i != 't' && visit[i] != 0){
			vc.push_back('a' + i);
		}
	}

	K = vc.size() < K? vc.size() : K;

	back(0);

	printf("%d", result);
}


void back(int limit){


	if(limit == K || limit == vc.size()){
		int allCount = 0;
		long long allBit = 0, bit = 0;
		for(int i = 0; i < K; i++){
			bit =  1 << (vc[inputChar[i]] - 'a') ;
			allBit|=bit;
		}

		for(int i = 0; i < N; i++){
			if( (mask[i] & allBit) == mask[i])
				allCount++;
		}

		if(result < allCount){
			result = allCount;
		}

		return;
	}
	for(int i = inputChar[limit-1]; i < vc.size(); i++){
		if(backTrackingVisit[i] == 0){
			backTrackingVisit[i] = 1;
			inputChar[limit] = i;
			back(limit+1);
			backTrackingVisit[i] = 0;
		}
	}
}