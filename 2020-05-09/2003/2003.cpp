#include <cstdio>
#include <vector>

using namespace std;

long long N, M;
long long mArray[10003];
vector<pair<int, int> > position;
long long getSum();

int main(){
	scanf("%lld %lld", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%lld", &mArray[i]);
	printf("%lld\n", getSum());
	for (auto p : position)
		printf("%d %d\n", p.first, p.second);
}

long long getSum(){
	int start = 0, end = 0;
	long long sum = 0, result = 0;
	while(end <= N ){
		if(sum < M){
			sum += mArray[end];
			end++;
		}else if(sum >= M){
			sum-=mArray[start];
			start++;
		}
		if(sum == M){
			position.push_back(make_pair(start, end-1));
			result++;
		}
	}
	return result;
}