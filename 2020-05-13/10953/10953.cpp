#include <cstdio>
#include <string>

using namespace std;

int T;
char order[10];

int main(){
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%s", &order);
		printf("%d\n", order[0]-'0' + order[2]-'0');
	}
}