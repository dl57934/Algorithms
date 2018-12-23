#include <stdio.h>

int main(){
	int arr[8] = {0,};
	char *result = "";
	for(int i = 0 ; i < 8; i++)
		scanf("%d", &arr[i]);
	for(int i = 0; i < 7; i++){
		if(arr[i]+1 == arr[i+1]){
			result = "ascending";
		}else if(arr[i] == arr[i+1]+1){
			result = "descending";
		}
		else{
			result = "mixed";
			break;
		}
	}
	printf("%s", result);
}