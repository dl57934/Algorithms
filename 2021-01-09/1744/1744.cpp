#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusVc, minusVc;

int main(){
	int N, num;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%d", &num);
		if(num <= 0)
			minusVc.push_back(num);
		else{
			plusVc.push_back(num);
		}
	}

	sort(minusVc.begin(), minusVc.end());
	sort(plusVc.begin(), plusVc.end(), greater<int>());

	int minusSize = minusVc.size();
	int answer = 0;
	int minusBaseNumber = 0;
	for(int i = 0; i < minusVc.size(); i++){
		if(minusBaseNumber == 0){
			minusBaseNumber = minusVc[i];
		}else{
			answer+=minusBaseNumber*minusVc[i];
			minusBaseNumber = 0;
		}
	}	

	int plusBaseNumber = 0;

	for(int i = 0; i < plusVc.size(); i++){
		if(plusBaseNumber == 0){
			plusBaseNumber = plusVc[i];
		}else{
			answer+=max(plusBaseNumber*plusVc[i],plusBaseNumber+plusVc[i]);
			plusBaseNumber = 0;
		}
	}

	answer+= minusBaseNumber + plusBaseNumber;
	
	printf("%d", answer);
}