#include <stdio.h>

#define ll long long

ll arr[1003]={0,};

ll result=0;
ll cluster=0;
ll getCluster(ll fileSize);

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	scanf("%lld", &cluster);

	for(int i = 0; i < N; i++)
		result+=getCluster(arr[i]);

	printf("%lld", result);
}

ll getCluster(ll fileSize){
	if(fileSize < cluster){
		if(fileSize==0)
			return 0;
		else
			return cluster;
	}
	else {
		if(fileSize%cluster == 0)
			return cluster * (fileSize/cluster);
		else
			return cluster * (fileSize/cluster+1);
		
	}
	
}