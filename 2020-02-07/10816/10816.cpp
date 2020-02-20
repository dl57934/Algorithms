#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int M;
int A[500002], B[500002];
int result[500002];

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	scanf("%d", &M);
	for(int i = 0; i < M; i++)
		scanf("%d", &B[i]);

	sort(A, A+N);

	for(int i = 0; i < M; i++){
		printf("%d ", (upper_bound(A, A+N, B[i])-A )- (lower_bound(A, A+N, B[i])-A));
	}
}	