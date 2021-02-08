#include <cstdio>
#include <string>

using namespace std;

int main(){
	int N;
	char previousWords[103], currentWords[103];
	string previos, current;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		if(i == 0){
			scanf("%s", &previousWords);
			previos = previousWords;
		}
		else{
			scanf("%s", &currentWords);
			current = currentWords;
			if(current[0] != previos.back()){
				printf("0");
				return 0;
			}
			previos = current;
		}
	}

	printf("1");
}