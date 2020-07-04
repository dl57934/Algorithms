#include <cstdio>
#include <vector>

int N, M;
int map[12][12];
vector<int> family;

void input();


int main(){

}

void input(){
	char order;
	scanf("%d %d", &N, &M);

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			scanf(" %c", &order);
			if(order == '#'){

			}else if(order == '.'){

			}else if(order == 'R'){

			}else if(order == 'B'){

			}else{

			}
		}
	}
}