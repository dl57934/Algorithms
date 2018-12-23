#include <stdio.h>
#include <string.h>

int main(){
	char croEng[101];
	scanf("%s", croEng);
	int count = 0;
	int length = strlen(croEng);
	for(int i = 0; i< length;i++){
		if(croEng[i] == 'd'){
			if(croEng[i+1]=='z' && croEng[i+2]=='='){
				i+=2;
				count+=2;
			}else if(croEng[i+1]=='-'){
				i+=1;
				count+=1;
			}
		}
		else if(croEng[i] == 'c'  || croEng[i] == 's' || croEng[i]=='z'){
			if(croEng[i+1]=='=' || croEng[i+1]=='-' ){
				i+=1;
				count+=1;
			}
		}else if(croEng[i] == 'l' || croEng[i] =='n'){
			if(croEng[i+1] == 'j'){
				i+=1;
				count+=1;
			}
		}
	}
	printf("%d", length-count);
}