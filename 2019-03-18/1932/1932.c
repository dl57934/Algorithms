#include <stdio.h>
#include <memory.h>
int arr[501][501];
int cpyArr[501][501];

int main(){
	int n;
	scanf("%d", &n);
	int max = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			scanf("%d", &arr[i-1][j]);

	memcpy(cpyArr, arr, sizeof(arr));
	
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j <= i; j++){
			if(j ==0){
				arr[i+1][j] += arr[i][j];
				arr[i+1][j+1] += arr[i][j];
			}else if(j == i){
				arr[i+1][j+1] = arr[i][j] + cpyArr[i+1][j+1];
				if(arr[i+1][j] < cpyArr[i+1][j] + arr[i][j]){
					arr[i+1][j] = arr[i][j] + cpyArr[i+1][j];
				}
			}else{
				if(arr[i+1][j] < cpyArr[i+1][j] + arr[i][j])
					arr[i+1][j] = arr[i][j]+cpyArr[i+1][j];
				if(arr[i+1][j+1] < cpyArr[i+1][j+1] + arr[i][j])
					arr[i+1][j+1] = arr[i][j]+cpyArr[i+1][j+1];
			}
		}
	}

	for(int i= 0; i < n; i++)
		if(max < arr[n-1][i])
			max = arr[n-1][i];

	printf("%d", max);

}



