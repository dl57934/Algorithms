import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bfr.readLine());
		int H, W, N;
		int roomNumber, height;
		for (int i = 0; i < T; i ++){
			String[] HWN = bfr.readLine().split(" ");
			H = modifyToInt(HWN[0]);
			N = modifyToInt(HWN[2]);
			roomNumber = getRoomNuber(H, N);
			height = getHeight(H, N);
			if(roomNumber < 10)
				System.out.printf("%d0%d\n", height, roomNumber);
			else 
				System.out.printf("%d%d\n", height, roomNumber);
		}	
	}

	public static int getRoomNuber(int H, int N){
		if(N%H == 0)
			return N/H;
		return N/H+1;
	}

	public static int getHeight(int H, int N){
		if(N%H == 0)
			return H;
		return N%H;
	}

	public static int modifyToInt(String number){
		return Integer.parseInt(number);
	}

}