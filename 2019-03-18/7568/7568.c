#include <stdio.h>
#include <memory.h>

typedef struct _athelete{
	int weight;
	int height;
	int rank;
}athelete;

athelete users[52];

int main(){
	int T;
	int rank = 1, count = 1;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d %d", &users[i].weight, &users[i].height);
		users[i].rank = 1;
	}

	for(int i = 0; i < T; i ++){
		for(int j = 0; j < T; j++){
			if(i!=j){
				if(users[i].weight < users[j].weight && users[i].height < users[j].height)
					users[i].rank +=1;
			}
		}
	}
	for(int i = 0; i < T; i ++)
		printf("%d ", users[i].rank);
}