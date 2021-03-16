#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector <char> order, order2(20);
int visit[20], L, C;
void backTrack(int n, int start);

int main(){
	char let;
	scanf("%d %d", &L, &C);

	for(int i = 0; i < C; i++){
		scanf(" %c", &let);
		order.push_back(let);
	}

	sort(order.begin(), order.end());
	backTrack(0, 0);
}

void backTrack(int n, int start){
	if(n == L){
		int visitLowCase = 0;
		for(int i = 0; i < L; i++){
			if(order2[i] == 'a' || order2[i] == 'e' || order2[i] == 'i'  || order2[i] == 'o'  || order2[i] == 'u'){
				visitLowCase+=1;
			}
		}

		if(visitLowCase >= 1 && L - visitLowCase >= 2){
			for(int i = 0; i < L; i++)
				printf("%c", order2[i]);
			printf("\n");
		}

		return ;
	}

	for(int i = start; i < order.size(); i++){
		if(visit[i] == 0){
			visit[i] = 1;
			order2[n] = order[i];
			backTrack(n+1, i+1);
			visit[i] = 0;	
		}
	}
}