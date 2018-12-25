#include <stdio.h>
#include <string.h>

int main(N){
	scanf("%d", &N);
	char inputData[101];
	int alphabet[26] = {0, };
	int result =N, length =0, lastIndex=0;
	int count = 0;
	char last = ' ';
	for (int i = 0; i < N;i++){
		memset(alphabet, 0, sizeof(alphabet));
		scanf("%s", inputData);
		length = strlen(inputData);
		last = inputData[0];
		for(int j = 0; j<length;j++){
			if(alphabet[inputData[j]-'a'] == 0){
				if(last != inputData[j]){
					alphabet[inputData[lastIndex]-'a'] = -1; 
				}
				lastIndex = j;
				last = inputData[j];
			}else if(alphabet[inputData[j]-'a'] == -1){
				result-=1;
				break;
			}
		}
	}
	printf("%d", result);
}