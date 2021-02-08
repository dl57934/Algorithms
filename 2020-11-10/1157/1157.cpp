#include <cstdio>
#include <string.h>

char words[1000002];
int alphabet[27];
int max, duplicate, maxIndex;

int main(){
	scanf("%s", &words);
	int length = strlen(words);

	for(int i = 0; i < length; i++)
		if(words[i] > 'Z')
			alphabet[words[i] - 'a'] += 1;
		else
			alphabet[words[i] - 'A'] += 1;
	
	for(int i = 0; i < 26; i++){
		if(alphabet[i] > max){
			max = alphabet[i];
			duplicate = 0;
			maxIndex = i;
		}else if(alphabet[i] == max && !duplicate)
			duplicate = 1;
	}

	if(duplicate)
		printf("?");
	else
		printf("%c", maxIndex + 'A');
}