#include <stdio.h>
#include <string.h>
int main(T){
	int R, stringLength;
	char S[22];
	scanf("%d", &T);
	for(int i = 0; i < T;i++){
		scanf("%d %s",&R ,&S);
		stringLength = strlen(S);
		for(int s=0; s<stringLength; s++){
			for(int r=0;r<R;r++){
				printf("%c",S[s]);
			}
			
		}
		printf("\n");
	}
}