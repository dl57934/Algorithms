#include <cstdio>
#include <string>
#include <map>
using namespace std;

map<string, int> position;

int main(){
	int N;
	char carNumber[14]; 
	scanf("%d", &N);

	for(int i = 0; i < N; i++){	
		scanf("%s", &carNumber);
		position[carNumber] = i;
	}

	int rightIndex = 0, wrongPosition = 0;

	int visited[1002] = {0, };

	for(int i = 0; i < N; i++){	
		scanf("%s", &carNumber);
		if(rightIndex < position[carNumber]){
			wrongPosition++;
			visited[position[carNumber]] = 1;
		}else if(rightIndex == position[carNumber]){
			for(int i = rightIndex + 1; i < N; i++){
				if(visited[i] == 0){
					rightIndex = i;
					break;
				}
			}
		}
	}

	printf("%d", wrongPosition);
}