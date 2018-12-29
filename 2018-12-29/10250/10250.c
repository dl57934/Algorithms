#include <stdio.h>

int getRoomNumber(int H, int N);
int getHeight(int H, int N);
int main(T){

	int H, W, N;
	int roomNumber, height;
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		scanf("%d %d %d", &H, &W, &N);
		roomNumber = getRoomNumber(H, W, N);
		height = getHeight(H, N);
		if(roomNumber < 10){
			printf("%d0%d\n",height, roomNumber);
		}else {
			printf("%d%d\n",height, roomNumber);
		}
	}
}

int getRoomNumber(int H, int N){
	if(N%H == 0)
		return N/H;
	return N/H+1;
}

int getHeight(int H, int N){
	if(N%H==0)
		return H;
	return N%H;
}