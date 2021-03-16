#include <string>
#include <cstdio>
#include <vector>
using namespace std;

void back(int limit, int startIndex);
void solve();
int result;
int visit[100002];
vector<string> sub(4), vc;
int N;

int main(){
	int testCase;
	scanf("%d", &testCase);
	for(int i = 0; i < testCase; i++)
		solve();
}


void solve(){
	result = 987654321;
	scanf("%d", &N);

	if(N >= 33){
		printf("0\n");
		return ;
	}

	char temp[7];
	vc.clear();
	for(int i = 0; i < 100000; i++)
		visit[i] = 0;

	for(int i = 0; i < N; i++){
		scanf("%s", &temp);
		string mbti(temp);
		vc.push_back(mbti);
	}

	back(0, 0);

	printf("%d\n", result);
}

void back(int limit, int startIndex){
	if(limit == 3){
		int diff = 0;
		for(int y = 0; y < 3; y++){
			for(int x = y+1; x < 3; x++){
				for(int letter = 0; letter < 4; letter++){
					if(sub[y][letter] != sub[x][letter])
						diff+=1;
				}
			}
		}

		if(result > diff)
			result = diff;
		
		return;
	}

	for(int i = startIndex; i < N; i++){
		if(visit[i] == 0){
			visit[i] = 1;
			sub[limit] = vc[i];
			back(limit+1, i);
			visit[i] = 0;
		}
	}
}