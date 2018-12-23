#include <stdio.h>
#include <string.h>

int main(){
	char words[1000];
	int index = 0;
	int result[27] = {};
	memset(result, -1, sizeof(result));
	scanf("%s", words);
	for(int i = 0; i< strlen(words); i++){
		if(result[words[i]-'a'] == -1){
			result[words[i]-'a'] = index;
			}
			index+=1;
		}
	for(int i =0; i< 26; i++)
		printf("%d ",result[i]);	
}