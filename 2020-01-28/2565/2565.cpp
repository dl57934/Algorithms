#include <cstdio>

typedef struct electric{
	int left;
	int right;
}electric;

int N;
int dp[502];

electric elec[102];

void mergeSort(int start, int end);
void merge(int start, int mid, int end);

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &elec[i].left, &elec[i].right);

	mergeSort(0, N-1);

}

void mergeSort(int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		mergeSort(start, mid);
		mergeSort(mid+1, end);
		merge(start, mid, end);
	}
}


void merge(int start, int mid, int end){
	electric temp[502];
	int part1 = start, index = start;
	int part2 = mid+1;
	for(int i = start; i <= end; i++)
		temp[i] = elec[i];

	while(part1 < mid && part2 < end){
		if(temp[part1].left < temp[part2].left){
			elec[index] = temp[part1];
			part1++;
		}else{
			elec[index] = temp[part2];
			part2++;
		}
		index++;
	}


	for(int i = 0; i <= mid-part1; i++)
		elec[i+index] = temp[part1+i];
}