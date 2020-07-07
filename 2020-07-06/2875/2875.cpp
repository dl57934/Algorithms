#include <cstdio>
// #include <vector>
#include <algorithm>
using namespace std;

// vector<int> team;
int woman, man, intern;
void input();
// void findTeam();

int main(){
	input();
	// findTeam();
	// sort(team.begin(), team.end());
	printf("%d",min({(woman + man - intern)/3 , woman/2, man}));
	// printf("%d", );
	// min({ (n + m - k) / 3,n / 2,m });
}

void input(){
	scanf("%d %d %d", &woman, &man, &intern);
}

// void findTeam(){
// 	int copyWoman, copyMan;
// 	for(int i = 0; i <= intern; i++){
// 		int womanIntern = i;
// 		int count = 0;
// 		int manIntern = intern - i;
// 		copyMan = man - manIntern;
// 		copyWoman = woman - womanIntern;
// 		while(copyWoman >= 2 && copyMan >= 1){
// 			copyWoman-=2, copyMan-=1;
// 			count++;
// 		}
// 		team.push_back(count);
// 	}
// }