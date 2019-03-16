#include <stdio.h>
#include <string.h>

char directory[5][18];
int wordsLength[5];

int main(){
	for(int i = 0; i < 5; i++){
		scanf("%s", &directory[i]);		
		wordsLength[i] = strlen(directory[i]);
	}

	for(int j = 0; j < 15; j++)
		for(int i = 0; i < 5; i++){
			if(wordsLength[i] > j)
				printf("%c", directory[i][j]);
		}
		printf("\n");

	
}