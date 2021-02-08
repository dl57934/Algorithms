#include <cstdio>
#include <string.h>

char order[102];
int num;

int isGroupWords();

int main(){
	int count = 0;
	scanf("%d", &num);

	for(int i = 0; i < num; i++){
		scanf("%s", &order);
		if(isGroupWords())
			count++;
	}

	printf("%d", count);
}

int isGroupWords(){
	int alphabet[26] = {0, };
	char isContinue ;

	int size = strlen(order);

	for(int i = 0; i < size; i++){
		if(alphabet[order[i]-'a'] == 0){
			alphabet[order[i]-'a'] += 1;
			isContinue = order[i];
		}else if(alphabet[order[i]-'a'] > 0 && order[i] != isContinue){
			return 0;
		}
	}

	return 1;
}