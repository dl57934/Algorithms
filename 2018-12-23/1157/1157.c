#include <stdio.h>
#include <string.h>

int main(){
	char words[1000002];
	int result[26] = {0,};
	scanf("%s", words);
	int max = 0, count =0;
	int index;
	int length = strlen(words);

	for(int i = 0; i < length; i++){
		if(words[i] > 96){
			words[i] = words[i]-32;
		}
		result[words[i]-'A']+=1;
		}

	for(int i = 0 ;i<26;i++){
		if(max < result[i]){
			max = result[i];
			count = 0;
			index = i;
		}else if(max == result[i]){
			count+=1;
		}
	}

	if(count > 0)
		printf("?");
	else 
		printf("%c", index + 'A');
}